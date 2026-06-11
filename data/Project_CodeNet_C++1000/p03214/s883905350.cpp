#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];

    int ans = 0;
    int num = abs(sum - n * a[0]);
    for (int i = 1; i < n; i++) {
        if (num > abs(sum - n * a[i])) {
            ans = i;
            num = abs(sum - n * a[i]);
        }
    }
    cout << ans << endl;
    return 0;
}
