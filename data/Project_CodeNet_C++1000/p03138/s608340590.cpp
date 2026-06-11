#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll gcd(ll a, ll b) {return (!b ? a : gcd(b, a % b));}
ll lcm(ll a, ll b) {return ((a*b)/gcd(a,b));}
bool cmp(int a,int b){return a>b;}

const ll mod = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;
const ld pi = 3.141592653589793;
const int N = 1e6 + 10;

long long modpow(long long n, long long k, long long mod)
{
if (k == 0) return 1;
long long r = modpow(n * n % mod, k >> 1, mod);
if (k & 1) r = r * n % mod;
return r;
}

void solve(){
   ll n,k;cin >> n >> k;
   vector<ll>a(n);
   for(int i = 0;i<n;i++) cin >> a[i];
   vector<ll>kk(60);
   vector<ll>b(60);
   ll temp = k;int cnt = 0;
   while(temp){if(temp%2)kk[cnt]++;cnt++;temp /= 2;}
   for(int i = 0;i<n;i++){
      temp = a[i];cnt = 0;
      while(temp){
        if(temp%2) b[cnt]++;
        cnt++;
        temp /= 2;
      }
   }
   ll ans = 0;bool go = 0;
   for(int i = 59;i>=0;i--){
   if(kk[i]==0&&go==0) ans += modpow(2,i,1e18)*b[i];
   else if(kk[i]==1&&go==0){
    if((n-b[i])<=b[i]) go = 1;
    b[i] = max(b[i],n-b[i]);ans += modpow(2,i,1e18)*b[i];}
   else {b[i] = max(b[i],n-b[i]);ans += modpow(2,i,1e18)*b[i];}
   }
   cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    solve();
    return 0;
}
