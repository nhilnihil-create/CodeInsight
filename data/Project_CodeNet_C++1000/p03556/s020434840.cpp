#include <bits/stdc++.h>

#define rep(l, r) for (int i = (l); i < (r); i++)

typedef long long ll;
 
using namespace std;

void solve() {
    int n;
    cin >> n;

    int x = 1;
    while (x * x <= n) {
        x++;
    }
    x--;

    cout << (x * x) << endl;
}

int main() {
    solve();

    return 0;
}
