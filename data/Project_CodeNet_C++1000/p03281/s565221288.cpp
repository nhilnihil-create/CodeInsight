#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int N;
    cin >> N;
    int ans = 0;
    int tmp;

    for (int n = 1; n <= N; n += 2) {
        tmp = 0;
        for (int i = 1; i <= sqrt(n); ++i) {
            if (n%i == 0) {
                if (n/i == i) tmp++;
                else tmp += 2;
            }
        }
        if (tmp == 8) ans++;
    }
    cout << ans << endl;
    return 0;
}