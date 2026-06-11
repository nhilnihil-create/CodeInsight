#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ft first
#define sd second
#define pb push_back
using namespace std;
const ll mod = 1e9+7;
const ll inf = 1e9+9;
 
ll power(ll a, ll b, ll m = mod) {
    ll x = 1;
    while(b) {
        if(b & 1) {
            x = 1ll * x * a % m;
        }
        a = 1ll * a * a % m;
        b /= 2;
    }
    return x;
}
 
mt19937_64 gen (random_device{}());
ll rint(ll a, ll b) { // generate rand int in [a, b]
    return a + gen() % (b - a + 1);
}
const int N = 2e5+9;
long long f[N], a[N], sum[N];
signed main() {  
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; 
    cin >> n;
    // n = 2e5;
    n++;
    a[1] = 2e5+1;
    for(int i = 2; i <= n; i++) {
        cin >> a[i];
        // a[i] = rint(1, (int)2e5);
    }
    f[1] = 1;
    for(int i = 2; i <= n; i++) {
        f[i] = f[i-1];
        if(a[i] == a[i-1]) {
            continue;
        }
        f[i] += sum[a[i]];
        if(f[i] >= mod) f[i] -= mod;
        sum[a[i]] += f[i-1];
        if(sum[a[i]] >= mod) sum[a[i]] -= mod;
    }
    cout << f[n] << "\n";







    return 0;
    
}