#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> a(m);
    int left = 0;
    int right = 0;
    for (int i = 0; i < m; i++) {
        cin >> a.at(i);
        if (a.at(i) < x) {
            left++;
        } else {
            right++;
        }
    }
    cout << min(left, right) << endl;
    return 0;
}
