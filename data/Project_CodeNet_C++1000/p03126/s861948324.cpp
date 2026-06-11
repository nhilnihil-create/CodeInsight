#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >>n >>m;

    vector<int> a(m);
    for (int i = 0; i < m; i++) {a.at(i) = 0;}

    int k, tmp;
    for (int i = 0; i < n; ++i) {
        cin >>k;
        for (int j = 0; j < k; ++j) {
            cin >>tmp;
            a.at(tmp-1) += 1;
        }
    }

    int ret = 0;
    for (int i = 0; i < m; ++i) {
        if (a.at(i) == n) ++ret;
    }
    cout << ret << endl;
    return 0;
}