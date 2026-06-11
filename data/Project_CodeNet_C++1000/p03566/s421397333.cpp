
#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
#define INF 100000000000000
#define ll long long
#define ull unsigned long long
#define M (int)(1e9+7)
#define P pair<int,int>
#define PLL pair<ll,ll>
#define FOR(i,m,n) for(int i=(int)m;i<(int)n;i++)
#define RFOR(i,m,n) for(int i=(int)m;i>=(int)n;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,n,0)
#define all(a) a.begin(),a.end()
#define IN(a,n) rep(i,n){ cin>>a[i]; }
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};
#define PI 3.14159265
#define F first
#define S second
#define PB push_back
#define EB emplace_back

int n;

int t[300],v[300];

int main(){
  cin>>n;
  rep(i,n){
    cin>>t[i];
    t[i]*=2;
    if(i)
      t[i]+=t[i-1];
  }
  rep(i,n){
    cin>>v[i];
    v[i]*=2;
  }
  vector<int> c(2*t[n-1]+1,inf);
  c[0]=0;
  c[t[n-1]]=0;
  int x=0;
  rep(i,n){
    FOR(j,x,t[i]+1){
      c[j]=min(c[j],v[i]);
    }
    x=t[i];
  }
  FOR(i,1,t[n-1]+1){
    c[i]=min(c[i],c[i-1]+1);
  }
  rrep(i,t[n-1]-1){
    c[i]=min(c[i],c[i+1]+1);
  }

  double ans=0;
  rep(i,t[n-1]){
    ans+=c[i]+c[i+1];
  }
  
  printf("%.10lf\n",ans/8);
}
