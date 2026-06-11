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

ld n;
int cnt1= 0;int cnt2 = 0;int cnt3 = 0;
vector<vector<vector<ld>>>dp(305,vector<vector<ld>>(305,vector<ld>(305,-1)));
vector<ld>a(305);

ld dfs(ld a,ld b,ld c){
     if(a==0&&b==0&&c==0) return 0;
     if(dp[a][b][c]>=0) return dp[a][b][c];
     ld d = a+b+c;
     ld ans = n/d;
     if(a) ans += dfs(a-1,b,c)*a/d;
     if(b) ans += dfs(a+1,b-1,c)*b/d;
     if(c) ans += dfs(a,b+1,c-1)*c/d;
     dp[a][b][c] = ans;
     return dp[a][b][c];
}
void solve(){
     cin >> n;
     for(int i = 0;i<n;i++) cin >> a[i];
     for(int i = 0;i<n;i++){
        if(a[i]==1) cnt1++;
        else if(a[i]==2) cnt2++;
        else cnt3++;
     }
     cout << fixed << setprecision(10)<<dfs(cnt1,cnt2,cnt3);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    solve();
    return 0;
}