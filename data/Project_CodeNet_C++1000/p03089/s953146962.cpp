#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <list>
#include <iomanip>
#include <queue>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;

int main() {

    ll N;

    cin >> N;

    vector<ll> b(N);

    rep(i, N) {
        cin >> b[i];
    }
    
    vector<ll> a;
    ll tmp = 0;


    while (b.size() != 0) {
        for (ll i = b.size() - 1; i >= 0; i--) {
            if (b[i] == i + 1) {
                a.insert(a.begin(), b[i]);
                b.erase(b.begin() + i);
                break;
            }
        }
        if (a.size() == tmp) {
            break;
        }
        tmp = a.size();
    }

    if (b.size() > 0) {
        cout << -1;
    }
    else {
        rep(i, N) {
            cout << a[i] << endl;
        }
    }

    return 0;
}
