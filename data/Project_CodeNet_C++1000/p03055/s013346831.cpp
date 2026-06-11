#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define MOD 1000000007
#define INF (1<<30)
#define LINF (1LL<<60)
#define endl "\n"
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define reprev(i,n) for(int (i)=(n-1);(i)>=0;(i)--)
#define Flag(x) (1<<(x))
#define Flagcount(x) __builtin_popcount(x)
#define pint pair<int,int>
#define pdouble pair<double,double>
#define plint pair<lint,lint>
typedef unsigned long long int ull;
typedef long long lint;

int L,place;
set<int> edge[200050];
set<int> edge2[200050];

void DFS(int x,int dep){
  while(!edge[x].empty()){
    int y=*edge[x].begin();
    edge[x].erase(y);
    edge[y].erase(x);
    DFS(y,dep+1);
  }
  if(dep>L) place=x;
  L=max(L,dep);
  return;
}

void DFS2(int x,int dep){
  while(!edge2[x].empty()){
    int y=*edge2[x].begin();
    edge2[x].erase(y);
    edge2[y].erase(x);
    DFS2(y,dep+1);
  }
  L=max(L,dep);
  return;
}

int main(void){
  int N;
  cin >> N;
  rep(i,N-1){
    int x,y;
    cin >> x >> y;
    x--,y--;
    edge[x].insert(y);
    edge[y].insert(x);
    edge2[x].insert(y);
    edge2[y].insert(x);
  }
  rep(i,N){
    if(edge[i].size()==1){
      DFS(i,1);
      L=0;
      DFS2(place,1);
      break;
    }
  }
  if(L%3==2) cout << "Second" << endl;
  else cout << "First" << endl;
}