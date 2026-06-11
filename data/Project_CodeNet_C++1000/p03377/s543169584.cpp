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
    int a, b, x; cin >> a >> b >> x;
    if(a <= x && a + b >= x) cout << "YES" << endl;
    else cout << "NO" << endl;
}
