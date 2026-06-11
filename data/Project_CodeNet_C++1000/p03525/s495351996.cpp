#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ft first
#define sd second
#define pb push_back
using namespace std;
const ll mod = 1e9+7;
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
signed main() {  
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<int> a(n+1);
    vector<int> f(13);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        f[a[i]]++;
    }
    if(f[0] > 1 || f[12] > 1) {
        cout << "0\n";
        return 0;
    }
    for(int i = 1; i < 12; i++) {
        if(f[i] > 2) {
            cout << "0\n";
            return 0;
        }
    }
    int ans = a[1];
    sort(a.begin() + 1, a.end());
    int rm = 0, lm = 24;
    for(int i = 1; i <= n; i++) {
        if(i & 1) {
            ans = min(ans, a[i] - rm);
            // cout << "rm: " << a[i] << " " << rm << endl;
            rm = a[i];
        } else {
            int pos = 24-a[i];
            ans = min(ans, lm - pos);
            // cout << "lm: " << pos << " " << lm << endl;
            lm = pos;
        }
        // cout << "A: " << ans << endl;
    }
    // cout << lm << " " << rm << endl;
    ans = min(ans, lm - rm);
    cout << ans << "\n";
    return 0;
    
}