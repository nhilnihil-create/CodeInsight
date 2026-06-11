#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
//cout << setprecision(20) << 

int main() {
    ll s; cin >> s;
    ll a = s;
    ll count = 2;
    map<ll, ll> m;
    m[s] = 1;
    while (true) {
        if (a % 2 == 1) {
            a = 3 * a + 1;
        }
        else {
            a /= 2;
        }
        if (m.count(a)) break;
        else m[a] = 1;
        count++;
    }
    cout << count << endl;
}