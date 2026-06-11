#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int amin = INT_MAX;
    int aminId = -1;
    int amax = INT_MIN;
    int amaxId = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (amax < a[i]) {
            amax = a[i];
            amaxId = i;
        }
        if (amin > a[i]) {
            amin = a[i];
            aminId = i;
        }
    }

    cout << n * 2 - 1 << endl;
    if (abs(amin) < abs(amax)) {
        // maxを全部に足す
        for (int i = 0; i < n; i++) {
            cout << amaxId + 1 << " " << i + 1 << endl;
        }
        // 先頭から累積和をとる
        for (int i = 0; i < n - 1; i++) {
            cout << i + 1 << " " << i + 1 + 1 << endl;
        }
    } else {
        // minを全部に足す
        for (int i = 0; i < n; i++) {
            cout << aminId + 1 << " " << i + 1 << endl;
        }
        // 末尾から累積和をとる
        for (int i = 1; i < n; i++) {
            cout << n - i + 1 << " " << n - i - 1 + 1 << endl;
        }
    }
}
