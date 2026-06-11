#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 100;
const int inf = 0x3f3f3f3f;

int n, m, len;
char s[maxn], t[maxn];
int sd[5][maxn], td[5][maxn];
map<int, char> mp;

int main() {
    //freopen("in.txt", "r", stdin);
    mp[1] = 'L';
    mp[2] = 'R';
    mp[3] = 'U';
    mp[4] = 'D';
    cin >> n >> m >> len;
    int sx, sy;
    cin >> sx >> sy;
    cin >> (s + 1);
    cin >> (t + 1);
    for (int i = 1; i <= len; i++) {
        for (int j = 1; j <= 4; j++) {
            sd[j][i] = sd[j][i - 1] + (s[i] == mp[j] ? 1 : 0);
            td[j][i] = td[j][i - 1] + (t[i] == mp[j] ? 1 : 0);
        }

        while (td[2][i] - sd[1][i] >= m - sy + 1) {
            td[2][i]--;
        }
        while (td[1][i] - sd[2][i] >= sy) {
            td[1][i]--;
        }
        while (td[3][i] - sd[4][i] >= sx) {
            td[3][i]--;
        }
        while (td[4][i] - sd[3][i] >= n - sx + 1) {
            td[4][i]--;
        }
        if (sd[1][i] - td[2][i - 1] >= sy) {
            printf("NO\n");
            return 0;
        }
        if (sd[2][i] - td[1][i - 1] >= m - sy + 1) {
            printf("NO\n");
            return 0;
        }

        if (sd[3][i] - td[4][i - 1] >= sx) {
            printf("NO\n");
            return 0;
        }
        if (sd[4][i] - td[3][i - 1]>= n - sx + 1) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
