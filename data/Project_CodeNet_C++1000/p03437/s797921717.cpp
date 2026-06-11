#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int x, y; cin >> x >> y;
    int i=1;
    if (x == y) {
        cout << "-1" << endl;
        return 0;
    }
    while (i * x<= 1e9) {
        if (i * x % y == 0) {
            i++;
            continue;
        }
        cout << i * x << endl;
        return 0;
    }
    cout << "-1" << endl;
}
