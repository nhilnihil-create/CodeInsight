#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define sz(a) a.size()
#define all(a) a.begin(),a.end()
#define lb lower_bound
#define ub upper_bound
#define owo ios_base::sync_with_stdio(0);cin.tie(0);
#define MOD (ll)(1e8)
#define INF (ll)(1e18)
#define debug(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false);\
debug("%s time : %.4fs\n", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> PII;
typedef pair<int,int> pii;
typedef vector<vector<int>> vii;
typedef vector<vector<ll>> VII;
ll gcd(ll a,ll b){if(!b)return a;else return gcd(b,a%b);}
int main()
{
 int n;
  cin>>n;
  map<string,vector<pii>>cnt;
  for(int i=1;i<=n;i++){
    string s;
    int a;
    cin>>s>>a;
    cnt[s].pb({a,i});
  }
  for(auto x:cnt){
   vector<pii>l = x.se;
    sort(all(l),greater<pii>());
    for(auto y:l)cout<<y.se<<'\n';
  }
}