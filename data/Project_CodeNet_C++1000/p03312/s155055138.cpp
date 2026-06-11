
#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
#define INF 1000000000000000
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
void init(){
  cin.tie(0);
  ios::sync_with_stdio(false);
}


int main(){
  ll s[300000];
  int n;
  cin>>n;
  FOR(i,1,n+1){
    cin>>s[i];
    s[i]+=s[i-1];
  }

  int l=1,r=3;
  ll ans=INF;
  FOR(m,2,n-1){
    while(abs(s[m]-2*s[l+1])<abs(s[m]-2*s[l])) l++;
    while(abs(s[n]-2*s[r+1]+s[m])<abs(s[n]-2*s[r]+s[m])) r++;
    vector<ll> v;
    v.PB(s[l]);
    v.PB(s[m]-s[l]);
    v.PB(s[r]-s[m]);
    v.PB(s[n]-s[r]);
    sort(all(v));
    ans=min(ans,v[3]-v[0]);
  }
  cout<<ans<<endl;
}
