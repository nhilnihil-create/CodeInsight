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
const int N = 5e5 + 10;
//const int mod = 1e9 + 7;

ll fac[N];

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void init() {
    fac[0] = 1;
    for (int i = 1; i < N; i++)
        fac[i] = fac[i - 1] * i % mod;
}

ll inv(ll a) {
	return binpow(a, mod - 2);
}

ll A(ll n, ll m) {
	return fac[n] * inv(fac[n - m]) % mod;
}

ll C(ll n, ll m) {
    return fac[n] * inv(fac[m]) % mod * inv(fac[n - m]) % mod;
}

void solve(){
     init();
     int n;cin >> n;
     int ans = 0;
     vector<int>a(105);
     for(int i = 2;i<=n;i++){
        int temp = i;
        for(int j = 2;j<100;j++){
            while(temp%j==0){temp /= j;a[j]++;}
        }
     }
     int cnt3 = 0;int cnt5 = 0;int cnt25 = 0;int cnt15 = 0;int cnt75 = 0;
     for(int i = 0;i<=100;i++){
            if(a[i]>=74) cnt75++;
            if(a[i]>=24)cnt25++;if(a[i]>=14) cnt15++;
            if(a[i]>=4)cnt5++;if(a[i]>=2)cnt3++;}
     ans += cnt75;
     ans += (cnt3-1)*(cnt25)+(cnt5-1)*cnt15;
     ans += (cnt5*(cnt5-1)*(cnt3-2))/2;
     cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    solve();
    return 0;
}