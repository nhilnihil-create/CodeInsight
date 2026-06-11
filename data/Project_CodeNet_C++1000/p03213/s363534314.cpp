#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    vector<int> v(N+1), c(5);
    for (int i = 2; i <= N; i++) {
        int x = i;
        for (int j = 2; j <= i; j++) {
            while (x % j == 0) {
                v[j]++;
                if (v[j] == 74) c[0]++;
                else if (v[j] == 24) c[1]++;
                else if (v[j] == 14) c[2]++;
                else if (v[j] == 4) c[3]++;
                else if (v[j] == 2) c[4]++;
                x /= j;
            }
        }
    }

    int ans = 0;
    ans += c[0];
    ans += c[1] * (c[4]-1);
    ans += c[2] * (c[3]-1);
    ans += c[3] * (c[3]-1) / 2 * (c[4]-2);
    cout << ans << "\n";
}