#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int check(int n, int x, int b, char l, char r, string s, string t) {
    int c = x;
    rep(i, n) {
        if (s[i] == l) --c;
        if (c <= 0) return 1;
        if (t[i] == r) c = min(b, c + 1);
    }
    c = x;
    rep(i, n) {
        if (s[i] == r) ++c;
        if (c > b) return 1;
        if (t[i] == l) c = max(1, c - 1);
    }
    return 0;
}

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    int sr, sc;
    cin >> sr >> sc;
    string s, t;
    cin >> s >> t;
    if (check(n, sr, h, 'U', 'D', s, t) || check(n, sc, w, 'L', 'R', s, t)) {
        puts("NO");
    }
    else {
        puts("YES");
    }
    return 0;
}
