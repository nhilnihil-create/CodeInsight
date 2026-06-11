#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;
const ll MOD = 1e9 + 7;

template<typename T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

int main() {
    int n; cin >> n;
    V<ll> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    ll g = v[0];
    for(int i = 1; i < n; i++){
        g = gcd(g, v[i]);
    }
    cout << g << endl;
}
