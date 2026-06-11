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
    int k = 1;
    while(1ll * k * (k+1) / 2 < (long long) n) k++;
    if(k * (k+1) / 2 != n) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    k++;
    int c = 1;
    vector<vector<int>> g(k+1);
    for(int i = 1; i <= k; i++) {
        for(int j = i+1; j <= k; j++) {
            g[i].push_back(c);
            g[j].push_back(c);
            c++;
        }
    }
    cout << k << "\n";
    for(int i = 1; i <= k; i++) {
        cout << g[i].size() << " ";
        for(int x: g[i]) cout << x << " ";
        cout << "\n";
    }


    return 0;
    
}