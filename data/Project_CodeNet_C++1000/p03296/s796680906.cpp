#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &ai: a) cin >> ai;
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        if (a[i - 1] == a[i]) a[i] = -1, cnt++;
    }
    cout << cnt << endl;
    return 0;
}
