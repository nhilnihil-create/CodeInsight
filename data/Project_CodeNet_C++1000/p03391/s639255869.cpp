#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>
#include <tuple>
#include <map>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;

    bool eq = true;
    ll mn = 1e9, s = 0;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        if (a != b) eq = false;
        if (a > b) mn = min(mn, b);
        s += a;
    }
    if (eq) cout << 0 << endl;
    else cout << s - mn << endl;

}