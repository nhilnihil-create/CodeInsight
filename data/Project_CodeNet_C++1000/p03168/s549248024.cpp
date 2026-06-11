#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define vl vector<ll>
#define pll pair<ll,ll>
#define mll map<ll, ll> 
#define rep(i,a)  for(ll i= 0;i < a;i++)
#define rep1(i,a) for(ll i= 1;i < a;i++)
#define foi(i, a, b)    for(ll i = a; i<b ; i++)
#define fod(i, a, b)    for(ll i = a; i>=b ; i--)
#define pb push_back
#define sz(v) v.size()
#define all(a) a.begin(), a.end()
#define max3(a, b, c)   max(max(a, b), c)
#define min3(a, b, c)   min(min(a, b), c)
#define MAX 1e6+5
#define MOD 1000000007
#define el "\n"
const ll INF = 2e9+5;
  
ll gcd(ll a, ll b){if(b==0)return a;return gcd(b, a%b);}
ll lcm(ll a, ll b){return a*b/gcd(a, b);}
ll isPrime(ll n){if(n<=3) return 1;if(n%2==0||n%3==0) return 0;
for(ll j=5;j*j<=n;j+=6){if(n%j == 0||n%(j+2) == 0) return 0;}return 1;}
 
using namespace std;
void solve(){
   ll n;
   cin>>n;
   vector<ld> p(n);
   rep(i,n)cin>>p[i];
   vector<vector<double>> dp(n+1,vector<double>(n+1,0.0));
   dp[0][0] = 1.0;
   // dp[0][1] = 1-p[0];
   // dp[1][0] = p[0];
   ll i=1,j=1;
   for(ll i=1;i<=n;i++){
      for(ll j=0;j<=i;j++){
         if(j==0) dp[i][j] = dp[i-1][j]*(1.0-p[i-1]);
         else dp[i][j] = dp[i-1][j-1]*p[i-1]+dp[i-1][j]*(1.0-p[i-1]);
      }
   }
   ld ans=0;
   for(ll i=n;i>n/2;i--){
      ans += dp[n][i];
   }
   cout<<fixed<<setprecision(10)<<ans;
}
 
int main() {
   #ifndef ONLINE_JUDGE
      freopen("input.txt", "r" , stdin);
      freopen("output.txt", "w" , stdout);
   #endif
   ios::sync_with_stdio(0); 
   cin.tie(0); cout.tie(0);   
   ll t;
   // cin>>t;
   t = 1;
   ll tc=0;
   while(tc++<t){
      // cout<<"Case #"<<tc<<": ";
      solve();
   }
   cerr<<"Time taken : "<<(double)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
   return 0;
}
