#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define rep(i, a, n) for (int i = a; i < n; ++i)

int main() {
    int n;
    cin >> n;

    bool flag = false;
    rep(i, 0, n / 4 + 1) {
        rep(j, 0, n / 7 + 1) {
            if (4 * i + 7 * j == n) {
                flag = true;
            }
        }
    }
    cout << (flag ? "Yes" : "No") << endl;

    return 0;
}
