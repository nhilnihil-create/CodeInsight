#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long ,long long>pll;

ll gcd(ll a, ll b) {return (!b ? a : gcd(b, a % b));}
ll lcm(ll a, ll b) {return ((a*b)/gcd(a,b));}
bool cmp(int a,int b){return a>b;}

const ll mod = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;
const ld pi = 3.141592653589793;

unsigned long long modpow(unsigned long long n, unsigned long long k, unsigned long long mod)
{
if (k == 0) return 1;
long long r = modpow(n * n % mod, k >> 1, mod);
if (k & 1) r = r * n % mod;
return r;
}

void solve(){
     int n;cin >> n;
     vector<ld>a(n+1);
     vector<vector<ld>>dp(n+2,vector<ld>(n+2,0.00));
     for(int i = 1;i<=n;i++)
        cin >> a[i];
     dp[0][0] = 1.00;
     for(int i = 1;i<=n;i++){
        for(int j = 0;j<=i;j++){
            int x = j;int y = i-j;
            if(x) dp[x][y] += dp[x-1][y]*a[i];
            if(y) dp[x][y] += dp[x][y-1]*(1.00-a[i]);
        }
     }
     int l = n,r = 0;ld ans = 0;
     while(l>r){
        ans += dp[l][r];
        l--;r++;
     }
     cout << fixed << setprecision(20) << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    solve();
    return 0;
}