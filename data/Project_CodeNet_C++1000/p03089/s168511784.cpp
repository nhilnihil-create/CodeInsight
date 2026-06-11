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
    cin >> n;
    list<int> b;
    for (int i = 0; i < n; i++) {
        int bi;
        cin >> bi;
        b.push_front(bi);
    }

    deque<int> ans;
    while (n) {
        int i = n--;
        bool erased = false;
        for (auto it = b.begin(); it != b.end(); it++, i--) {
            if (*it == i) {
                b.erase(it);
                ans.push_front(i);
                erased = true;
                break;
            }
        }
        if (!erased) {
            ans.clear();
            ans.push_front(-1);
            break;
        }
    }

    for (int a : ans) cout << a << endl;
}
