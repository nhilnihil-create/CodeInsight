#include <algorithm>
#include <climits>
#include <cmath>
#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>

using Graph = std::vector<std::vector<int>>;
using WGraph = std::vector<std::vector<std::pair<int, long long>>>;
using ll = long long;
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<ll> a(n);
    for (int i=0; i<n; i++) {
        cin >> a.at(i);
    }
    ll must = 0;
    for (int i=n-1; i>=0; i--) {
        if (a.at(i) < must) {
            cout << -1 << endl;
            return 0;
        } else {
            must = max(must, a.at(i));
            must--;
        }
    }
    if (must >= 0) {
        cout << -1 << endl;
        return 0;
    }

    ll cnt = a.at(n-1);
    for (int i=n-2; i>=0; i--) {
        if (a.at(i) >= a.at(i+1)) {
            cnt += a.at(i);
        }
    }
    cout << cnt << endl;

    return 0;
}
 