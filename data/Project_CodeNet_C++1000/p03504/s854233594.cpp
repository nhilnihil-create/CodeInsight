#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,n) for(int i=(int)(j);i<(int)(n);i++)
#define REP(i,j,n) for(int i=(int)(j);i<=(int)(n);i++)
#define MOD 1000000007
#define int long long
#define ALL(a) (a).begin(),(a).end()
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>
#define priq priority_queue<int>
#define disup(A,key) distance(A.begin(),upper_bound(ALL(A),(int)(key)))
#define dislow(A,key) distance(A.begin(),lower_bound(ALL(A),(int)(key)))
#define tii tuple<int,int,int>
const int MAX=200001;
signed main(){
  int N,C; cin>>N>>C;
  vector<bitset<30>> B(MAX);
  rep(i,0,N){
    int X,Y,Z; cin>>X>>Y>>Z;
    REP(j,X*2-1,Y*2) B[j].set(Z-1);
  }
  int ans=0;
  rep(i,0,MAX){
    ans=max(ans,(int)B[i].count());
  }
  cout<<ans<<endl;
  }
