#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<int> x(n), tmp(n);
    rep(i,n) {
        cin >> x[i];
        tmp[i] = x[i];
    }
    sort(tmp.begin(), tmp.end());
    int f = tmp[n / 2 - 1], b = tmp[n / 2];
    
    for (int i = 0; i < n; i++)
    {
        if (x[i] <= f) {
            cout << b << endl;
        }
        else if (x[i] >= b) {
            cout << f << endl;
        }
    }
    return 0;
}