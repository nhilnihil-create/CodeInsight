#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#define ll long long
//#define local

using namespace std;

const int MOD = 1e9+7;
const int inf = 0x3f3f3f3f;
const int maxn = 1e3+100;
const double PI = acos(-1.0);

ll x[maxn], y[maxn];
vector <ll> ans;
vector <string> s(maxn, "");
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
char str[10] = "DLUR";

int main() {
#ifdef local
    if(freopen("/Users/Andrew/Desktop/data.txt", "r", stdin) == NULL) printf("can't open this file!\n");
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld%lld", &x[i], &y[i]);
    }
    for (int i = 1; i < n; ++i) {
        if (((x[i]+y[i])&1) != ((x[0]+y[0])&1)) {
            cout << -1 << endl;
            return 0;
        }
    }
    for (ll i = 1; i < 2e9; i <<= 1) {
        ans.push_back(i);
    }
    if (((x[0]+y[0]) & 1) == 0) {
        ans.push_back(1);
    }
    for (int i = 0; i < n; ++i) {
        for (ll k = ans.size()-1; k >= 0; --k) {
            ll step = ans[k];
            int select = -1;
            ll mind = 1e18;
            for (int j = 0; j < 4; ++j) {
                if (mind > (abs(x[i]+step*dx[j]) + abs(y[i]+step*dy[j]))) {
                    mind = abs(x[i]+step*dx[j]) + abs(y[i]+step*dy[j]);
                    select = j;
                }
            }
            x[i] += step*dx[select];
            y[i] += step*dy[select];
            s[i].push_back(str[select]);
        }
    }
    cout << ans.size() << endl;
    for (ll k = ans.size()-1; k >= 0; --k) {
        if (k < ans.size()-1) cout << " ";
        cout << ans[k];
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
        cout << s[i] << endl;
    }
#ifdef local
    fclose(stdin);
#endif
    return 0;
}










