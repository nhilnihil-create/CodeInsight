#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define rep(i, a, n) for (int i = a; i < n; ++i)

int main() {
    int x;
    cin >> x;

    vector<bool> ex(x + 1);
    ex[1] = true;
    rep(i, 2, x + 1) {
        int v = i * i;
        while (v <= x) {
            ex[v] = true;
            v *= i;
        }
    }
    for (int i = x; i >= 1; --i) {
        if (ex[i]) {
            cout << i << endl;
            return 0;
        }
    }
}
