#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M (ll)1000000007
#define MM (ll)1e8
#define INF (ll)1e18
#define arep(i, x, n) for (long long i = x; i < n; i++)
#define rep(i, n) for (long long i = 0; i < n; ++i)
#define pi 3.141592653589793
#define eps 0.00000001

int main() {
    char s[52][52];

    ll h;
    ll w;
    cin >> h >> w;

    fill(&s[0][0], &s[0][0] + sizeof(s), '.');

    arep(i, 1, h + 1) arep(j, 1, w + 1) cin >> s[j][i];

    bool isOK = true;
    arep(i, 1, h) {
        arep(j, 1, w) {
            if (s[j][i] == '#') {
                if (s[j - 1][i] == '.' && s[j + 1][i] == '.' &&
                    s[j][i - 1] == '.' && s[j][i + 1] == '.') {
                    isOK = false;
                    break;
                }
            }
        }
        if (!isOK) break;
    }

    if (isOK)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}