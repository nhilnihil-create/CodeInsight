#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int ab[4];

int main() {
    memset(ab, 0, sizeof(ab));
    for (int i = 0; i < 3; i++) {
        int a, b;
        cin >> a >> b;
        ab[a-1]++;
        ab[b-1]++;
    }

    bool f = false;
    int odd = 0;
    for (int i = 0; i < 4; i++) {
        if (ab[i] % 2 == 1) {
            odd++;
        }
    }

    if (odd == 0 || odd == 2) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
