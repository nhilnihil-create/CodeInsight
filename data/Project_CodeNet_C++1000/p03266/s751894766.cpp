#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;
const ll MOD = 1e9 + 7;


int main() {
    ll n, k; cin >> n >> k;

    map<ll, ll> m;
    for(int i = 1; i <= n; i++){
        m[i % k]++;
    }

    ll r = k / 2;
    if(k % 2 == 0) cout << m[0] * m[0] * m[0] + m[r] * m[r] * m[r] << endl;
    else cout << m[0] * m[0] * m[0] << endl;
}
