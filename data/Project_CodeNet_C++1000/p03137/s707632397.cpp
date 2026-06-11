#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll gcd(ll a,ll b){if(a%b==0){return b;}else{return(gcd(b,a%b));}}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
const int INF=1e9;
const ll INFS=1e18;
const int MOD=INF+7;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};
const double PI=acos(-1);

int main() {
  int n,m;
  cin>>n>>m;
  vector<int> x(m);
  rep(i,m) cin>>x[i];
  sort(all(x));
  vector<int> dist(m-1);
  rep(i,m-1){
    dist[i]=x[i+1]-x[i];
  }
  sort(all(dist));
  int ans=0;
  if(m-n<=0){
    cout<<0<<endl;
    return 0;
  }
  rep(i,m-n){
    ans+=dist[i];
  }
  cout<<ans<<endl;
}