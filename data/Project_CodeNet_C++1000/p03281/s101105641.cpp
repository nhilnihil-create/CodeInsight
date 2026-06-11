#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ll N;
    cin >> N;
    int ans = 0;
    for (int i = 1; i <= N; i += 2) {
        int tmp = 0;
        for (int j = 1; j <= i; ++j) {
            if (i % j == 0) tmp++;
        }
        if (tmp == 8) ans++;
    }
    cout << ans << endl;
}