#include <bits/stdc++.h>
#include <boost/range/adaptor/reversed.hpp>
#include <boost/range/algorithm/sort.hpp>
#include <boost/range/irange.hpp>

using namespace std;
using boost::irange;
using boost::sort;
using boost::adaptors::reversed;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    int ans = 0;
    deque<char> a;
    for (int i = 0, j = n - 1; j - i > 0;) {
        if (s[i] == s[j]) {
            i += 1;
            j -= 1;
        } else {
            if (s[i] == 'x') {
                ans += 1;
                i += 1;
            } else if (s[j] == 'x') {
                ans += 1;
                j -= 1;
            } else {
                ans = -1;
                break;
            }
        }
    }

    cout << ans << endl;
}
