#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n; cin >> n;
    vector<int> x(n);
    rep(i, n) cin >> x[i];
    vector<int> x_sort = x;
    sort(x_sort.begin(), x_sort.end());
    int median = n/2;
    rep(i, n) {
        if (x[i] <= x_sort[median-1]) {
            cout << x_sort[median] << endl;
        }
        else {
            cout << x_sort[median-1] << endl;
        }
    }
}