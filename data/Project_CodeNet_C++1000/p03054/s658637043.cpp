#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
#include <string.h>
#define rep(i,n) for (int i = 0; i < (int)n; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<pi, pi> pp;
typedef pair<ll, ll> pl;
double PI = 3.1415926535897932;
const double EPS = 1e-9;
const ll MOD = 1000000007;
const int inf = 1 << 30;
const ll linf = 1LL << 60;

int h, w, n;
int x, y;
string s, t;

int main() {
    cin >> h >> w >> n;
    cin >> x >> y;
    cin >> s >> t;
    int up = 0, right = w+1, down = h+1, left = 0;
    for (int i = n-1; i >= 0; i--) {
        if (t[i] == 'L') right = min(w+1, right+1);
        if (t[i] == 'R') left = max(0, left-1);
        if (t[i] == 'U') down = min(h+1, down+1);
        if (t[i] == 'D') up = max(0, up-1);

        if (s[i] == 'L') left = left+1;
        if (s[i] == 'R') right = right-1;
        if (s[i] == 'U') up = up+1;
        if (s[i] == 'D') down = down-1;


        if (down-up <= 1 || right-left <= 1) {
            cout << "NO" << endl;
            return 0;
        }
    }
    if (up >= x || x >= down || left >= y || y >= right) cout << "NO" << endl;
    else cout << "YES" << endl;
}