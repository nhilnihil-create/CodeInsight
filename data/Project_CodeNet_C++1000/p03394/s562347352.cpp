#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
template<class T> ostream& operator<<(ostream& os, const vector<T>& vec) { for (auto &vi: vec) os << vi << " "; return os; }

int main() {
    int n; cin >> n;
    if (n == 3) return !(cout << 2 << " " << 3 << " " << 25 << endl);
    vector<int> a = {2, 4, 3, 9, 8, 10, 6, 12};
    vector<int> res;
    if (n & 1) res.emplace_back(30000), n--;
    for (int i = 0; i < n; i++) res.emplace_back(a[i % 8] + i / 8 * 12);
    cout << res << endl;
    return 0;
}
