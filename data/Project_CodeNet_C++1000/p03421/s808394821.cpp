#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
template<class T> ostream& operator<<(ostream& os, const vector<T>& vec) { for (auto &vi: vec) os << vi << " "; return os; }

int main() {
    int n; cin >> n;
    long long inc, dec; cin >> inc >> dec;
    if (inc + dec - 1 > n || inc * dec < n) return !(cout << -1 << endl);
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    #define rev(s, t) reverse(begin(a) + s, begin(a) + t);
    if (dec > 1) {
        if (inc * dec == n) {
            for (int i = 0; i < n; i += dec) rev(i, i + dec);
        } else {
            int q = (n - inc) / (dec - 1);
            int r = (n - inc) % (dec - 1);
            for (int i = 0; i < dec * q; i += dec) rev(i, i + dec);
            rev(dec * q, dec * q + r + 1);
        }
    }
    cout << a << endl;
    return 0;
}
