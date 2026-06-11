#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> x(n), y;
    for (auto i = 0; i < n; i++) cin >> x[i];
    y = x; sort(y.begin(), y.end());
    int a = y[n / 2 - 1], b = y[n / 2];

    for (auto i = 0; i < n; i++) {
        if(x[i] >= b) cout << a << endl;
        else cout << b << endl;
    }
    return 0;
}