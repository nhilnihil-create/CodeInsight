#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    int n, a;
    cin >> n >> a;
    n = n % 500;
    if (n <= a) {
        cout << "Yes" << endl;
        return 0;
    }
    if (a == 0) {
        cout << "No" << endl;
        return 0;
    }
    cout << "No" << endl;

    return 0;
}