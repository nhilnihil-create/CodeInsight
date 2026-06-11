#include <bits/stdc++.h>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;


int main() {
    ll n, m, d; cin >> n >> m >> d;
    if (d == 0) {
        cout << fixed;
        cout << setprecision(7) << (double)((n-d) * (m-1)) / (double)(n*n) << endl;
    } else {
        cout << fixed;
        cout << setprecision(7) << (double)(2 * (n-d) * (m-1)) / (double)(n*n) << endl;
    }

    return 0;
}


    
