#include <bits/stdc++.h>
#define range(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) range(i, 0, a)
using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> a(n);
    rep (i, n) cin >> a[i];
    sort(a.begin(), a.end());

    int mini = 1e9, num;
    rep (i, n - 1) {
        if (n % 2) {
            if (mini > abs(a[i] - (a.back() + 1) / 2)) {
                mini = abs(a[i] - (a.back() + 1) / 2);
                num = a[i];
            }
        }
        else {
            if (mini > abs(a[i] - a.back() / 2)) {
                mini = abs(a[i] - a.back() / 2);
                num = a[i];
            }
            if (mini > abs(a[i] - (a.back() / 2 + 1))) {
                mini = abs(a[i] - (a.back() / 2 + 1));
                num = a[i];
            }
        }
    }

    cout << a.back() << " " << num << endl;

    return 0;
}