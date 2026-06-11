#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstdio>
#include <map>
#include <set>
#include <utility>
#include <string>
#include <functional>
#include <queue>
#include <stack>

using namespace std;

typedef long long ll;
typedef long double ld;




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    int i, j;
    for(i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if(a[n - 1] % 2 == 0) {
        int mid = a[n - 1] / 2;
        int e = -1, mind = 1e9 + 1;
        for(i = 0; i < n - 1; i++) {
            if(abs(mid - a[i]) < mind) {
                mind = abs(mid - a[i]);
                e = a[i];
            }
        }
        swap(e, a[n - 1]);
        cout << e << " " << a[n - 1];
    }
    else {
        int m1 = a[n - 1] / 2;
        int m2 = m1 + 1;
        int mind = 1e9 + 1;
        int e;
        for(i = 0; i < n - 1; i++) {
            if(abs(m1 - a[i]) < mind) {
                mind = abs(m1 - a[i]);
                e = a[i];
            }
            if(abs(m2 - a[i]) < mind) {
                mind = abs(m2 - a[i]);
                e = a[i];
            }
        }
        swap(e, a[n - 1]);
        cout << e << " " << a[n - 1];
    }

    return 0;
}

