#include<bits/stdc++.h>
using namespace std;
#define inf 1e9
#define ll long long 
#define M 1000000007
#define P pair<int,int>
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define rep(i,n) FOR(i,0,n)
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};
#define PI 3.14159265

int n;
bool c[200][200];
int ans;

int main(){
  cin>>n;
  rep(i,n){
    int a,b;
    cin>>a>>b;
    c[b][a] = true;
  }
  vector<P> v;

  rep(i,n){
    int a,b;
    cin>>a>>b;
    v.push_back(P(b,a));
  }

  sort(v.begin(),v.end());

  rep(i,n){
    P p = v[i];
    int x=-1,y=-1;
    rep(j,p.second){
      rep(k,p.first){
        if(c[k][j]){
          x = j; y =k;
        }
      }
    }
    if(x!=-1){
      c[y][x] = false;
      ans++;
    }
  }

  cout<<ans<<endl;

  return 0;
}


