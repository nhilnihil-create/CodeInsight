#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define vi vector<ll>
#define vvi vector<vi>
#define DBG_N(hoge) cerr<<" "<<(hoge)<<endl;
#define DBG cerr<<"!"<<endl;
#define BITLE(n) (1LL<<((ll)n))
#define BITCNT(n) (__builtin_popcountll(n))
#define SUBS(s,f,t) ((s).substr((f)-1,(t)-(f)+1))
#define ALL(a) (a).begin(),(a).end()
using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll h,w;cin>>h>>w;
  ll n;cin>>n;
  ll x,y;cin>>x>>y;
  string t,a;cin>>t>>a;
  bool ans=true;
  ll nx=x,ny=y;
  for(int i=0;i<n;i++){
    if(t[i]=='R'){
      ny++;
    }
    if(ny>w)ans=false;
    if(a[i]=='L'&&ny>1)
      ny--;
  }
  nx=x;ny=y;
  for(int i=0;i<n;i++){
    if(t[i]=='L'){
      ny--;
    }
    if(ny<1)ans=false;
    if(a[i]=='R'&&ny<w)
      ny++;
  }
  nx=x;ny=y;
  for(int i=0;i<n;i++){
    if(t[i]=='U'){
      nx--;
    }
    if(nx<1)ans=false;
    if(a[i]=='D'&&nx<h)
      nx++;
  }
  nx=x;ny=y;
  for(int i=0;i<n;i++){
    if(t[i]=='D'){
      nx++;
    }
    if(nx>h)ans=false;
    if(a[i]=='U'&&nx>1)
      nx--;
  }
  if(ans)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}
