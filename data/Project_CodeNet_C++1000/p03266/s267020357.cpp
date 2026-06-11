#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;

int main() {
    ll n, k; cin >> n >> k;

    ll a = n / k;
    ll b = (n + (k / 2)) / k;

    if(k % 2 == 0) cout << a * a * a + b * b * b << endl;
    else cout << a * a * a << endl;
}
