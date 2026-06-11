#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    for (int i=0; i<=n; i += 4) {
        int d = n - i;
        if (d%7) continue;
        else {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}