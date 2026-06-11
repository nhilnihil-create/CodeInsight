#include <bits/stdc++.h>
#include <boost/range/adaptor/reversed.hpp>
#include <boost/range/algorithm/sort.hpp>
#include <boost/range/irange.hpp>

using namespace std;
using boost::irange;
using boost::sort;
using boost::adaptors::reversed;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int w = 0;
    int b = 0;
    for (int i = 0; i < n; i++) if (s[i] == '.') w += 1;
    int ans = w + b;
    for (int i = 0; i < n; i++) {
        if (s[i] == '.') {
            w -= 1;
        } else {
            b += 1;
        }
        ans = min(w + b, ans);
    }

    cout << ans << endl;
}
