#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9+7;


int main() {
    ll n; cin >> n;
    string s = to_string(n);
    int l = s.size();
    ll m = s[0] - '0' - 1;
    ll sum = 0;
    for(int i = 0; i < l; i++) sum += s[i] - '0';
    cout << max(sum, m + (l - 1) * 9) << endl;

    return 0;
}
