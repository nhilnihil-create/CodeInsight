#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9+7;
const ll INF = 1LL << 60;


int main() {
    int a,b,c; cin >> a >> b >> c;
    if(a <= c && c <= b) cout << "Yes" << endl;
    else if(b <= c && c <= a) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
