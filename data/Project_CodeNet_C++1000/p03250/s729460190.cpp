#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long

const int MOD =  1000000007;
const int IINF = INT_MAX;
const ll INF = 1LL << 60;


int main() {
    int a, b, c; cin >> a >> b >> c;
    V<int> v({a, b, c});
    sort(ALL(v));
    cout << v[2] * 10 + v[1] + v[0] << endl;

    return 0;
}
