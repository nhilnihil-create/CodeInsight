#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>
#include <vector>
#include <iomanip>
#include <map>

using namespace std;

#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef long double ld;

const ll SIZE = 1e5 * 3 + 10;



int main() {
    fastInp;

    ll m, k;
    cin >> m >> k;
    ll nms = (1ll << m), x = 0;
    if (k == 0) {
        for (int i = 0; i < nms; i++) {
            cout << i << " " << i << " ";
        }
        return 0;
    }
    for (int i = 0; i < nms; i++) {
        if (k != i) {
            x ^= i;
        }
    }

    if (x != k) {
        cout << "-1";
        return 0;
    }

    for (int i = 0; i < nms; i++) {
        if (k != i) cout << i << " ";
    }

    cout << k << " ";

    for (int i = nms - 1; i >= 0; i--) {
        if (k != i) cout << i << " ";
    }

    cout << k << " ";
    return 0;
}

