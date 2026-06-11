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
    ll l,r;
    cin >> l >> r;
    if(r-l<4){
        ll ans = l;
        for(ll i = l+1;i<=r;i++) ans = ans^i;
        cout << ans;
        return;
    }
    if((l^(l+1))!=1&&(r^(r-1))==1){
        if((r-l)%4) cout << (l^1);
        else cout << (l^0);
    }
    else if((l^(l+1))==1&&(r^(r-1))!=1){
        if((r-l)%4) cout << (r^1);
        else cout << (r^0);
    }
    else if((l^(l+1))!=1&&(r^(r-1))!=1){
        ll ans = (l^r);
        if((r-l-1)%4) cout << (ans^1);
        else cout << (ans^0);
    }
    else{
        if((r-l+1)%4) cout << 1;
        else cout << 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    solve();
    return 0;
}
