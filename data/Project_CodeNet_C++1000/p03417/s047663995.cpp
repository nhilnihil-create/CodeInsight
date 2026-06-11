#include <iostream>
#define rep(i,n) for(int (i)=0;(i)<(n);++(i))
#define all(x) (x).begin(),(x).end()
#define dump(x) cout << #x << " = " << (x) << endl

using namespace std;
using ll = long long;

int main() {
    ll n, m; cin >> n >> m;

    if (n == 1 && m == 1) {
        cout << 1 << endl;
        return 0;
    }

    if (n == 1) {
        cout << max(0ll, m - 2) << endl;
        return 0;
    }

    if (m == 1) {
        cout << max(0ll, n - 2) << endl;
        return 0;
    }

    cout << (n - 2) * (m - 2) << endl;
    return 0;
}