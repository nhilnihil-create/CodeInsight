#include <bits/stdc++.h>
#define ll long long
#define INF LLONG_MAX 
#define dd double 
#define fi first
#define se second
#define rep(i,a,b) for(ll i=a;i<=b;i++)
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
#define dll deque<long long>
#define qll queue<long long>
#define vll vector<long long>
#define vc vector<char>
#define vs vector<string>
#define vvll vector<vector<ll>>
#define vpll vector<pair<long long,long long>>
#define vpcl vector<pair<char,long long>>
#define vpsl vector<pair<string,long long>>
#define stll stack<long long>
#define stc stack<char>
#define mll map<long long,long long>
#define pll pair<long long,long long>
#define psl pair<string,long long>
#define mcl map<char,long long>
#define msl map<string,long long>
#define pcl pair<char,long long>
#define mmll multimap<long long,long long> 
#define mmcl multimap<char,long long>
#define mmsl multimap<string,long long>
#define sll set<long long>
#define sc  set<char>
#define ss  set<string>
#define msll multiset<long long>
#define msc  multiset<char>
#define mss  multiset<string>
#define lb lower_bound
#define up upper_bound
#define lt length
#define clr clear
#define ap append
#define sz size
#define sub substr
#define ull unsigned long long int
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
//#include <boost/multiprecision/cpp_int.hpp> 
//using boost::multiprecision::cpp_int; 
using namespace __gnu_pbds; 
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 

ll modexp(ll x,ll n,ll p){    //modular exponential function
  if(n==0){return 1;}
  ll u = modexp(x,n/2,p);
  u = u*u%p;
  if(n%2==1){u=(u*x)%p;}
  return u;
}

ll gcd (ll a, ll b) {     //Eulers algorithm
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

ll arr[21][21];
ll dp[(1<<21)+1];
ll m = 1000000007;
ll f(ll s,ll n){
  ll j = __builtin_popcount(s);
  if(s == (1<<n)-1){return 1;}
  if(dp[s]!=-1){return dp[s];}
//   cout<<j<<"\n";
  ll ans = 0;
  rep(i,0,n-1){
      if( (s & 1<<i)==0 && arr[i][j]==1){
          ans = (ans + f((s | 1<<i),n)%m)%m;
      }
  }
  dp[s] = ans;
  return ans;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll n; cin>>n;
    memset(dp,-1,sizeof(dp));
    rep(i,0,n-1){
        rep(j,0,n-1){
            cin>>arr[i][j];
        }
    }
    cout<<f(0,n);
}
