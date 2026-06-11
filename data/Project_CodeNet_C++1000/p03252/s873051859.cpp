#include <bits/stdc++.h>
#include <boost/range/adaptor/reversed.hpp>
#include <boost/range/algorithm/sort.hpp>
#include <boost/range/irange.hpp>

using namespace std;
using boost::irange;
using boost::sort;
using boost::adaptors::reversed;

int main() {
    string s, t;
    cin >> s >> t;
    map<char, int> sa, ta;
    int s_v = 1;
    for (char c : s) if (!sa[c]) sa[c] = s_v++;
    int t_v = 1;
    for (char c : t) if (!ta[c]) ta[c] = t_v++;
    bool cond = true;
    for (int i = 0; i < (int)s.length(); i++) {
        if (sa[s[i]] != ta[t[i]]) {
            cond = false;
            break;
        }
    }
    cout << (cond ? "Yes" : "No") << endl;
}
