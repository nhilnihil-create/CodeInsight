#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
using llong = long long;

llong k;
llong a[100005];

llong res(llong x) {
    for (int i = 0; i < k; i++) {
        x -= x % a[i];
    }
    return x;
}

int main() {
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }

    llong minv;
    llong maxv;

    {
        llong valid, invalid;
        valid = 1ll << 60ll;
        invalid = 0;

        while (valid - invalid > 1) {
            llong mid = (valid + invalid) / 2;
            if (res(mid) >= 2) {
                valid = mid;
            }
            else {
                invalid = mid;
            }
        }
        minv = valid;
    }
    {
        llong valid, invalid;
        valid = 0;
        invalid = 1ll << 60ll;

        while (invalid - valid > 1) {
            llong mid = (valid + invalid) / 2;
            if (res(mid) > 2) {
                invalid = mid;
            }
            else {
                valid = mid;
            }
        }
        maxv = valid;
    }

    if (res(minv) != 2) cout << -1 << endl;
    else cout << minv << ' ' << maxv << endl;

    return 0;
}
