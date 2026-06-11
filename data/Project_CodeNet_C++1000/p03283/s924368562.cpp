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

 long long modpow(long long n, long long k,long long mod)
{
if (k == 0) return 1;
long long r = modpow(n * n % mod, k >> 1, mod);
if (k & 1) r = r * n % mod;
return r;
}

void solve(){
     int n,m,q;
     cin >> n >> m >> q;
     vector<vector<int>>a(600,vector<int>(600,0));
     vector<vector<int>>sum(600,vector<int>(600,0));
     for(int i = 0;i<m;i++){
        int l,r;cin >> l >> r;
        a[l][r]++;
     }
     for(int i = 0;i<=n;i++){
        for(int j = 1;i+j<=n;j++){
            sum[j][i+j] = a[j][i+j]+sum[j+1][i+j]+sum[j][i+j-1]-sum[j+1][i+j-1];
        }
     }
     while(q--){
        int l,r;cin >> l >> r;
        cout << sum[l][r] <<endl;
     }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    solve();
    return 0;
}
