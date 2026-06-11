#include <bits/stdc++.h>

#define rep(x, y) for (int i = (x); i < (y); i++)

typedef long long ll;

using namespace std;

int main() {
    int k;
    cin >> k;

    int cnt = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            if (i % 2 == 0 && j % 2 != 0) cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
