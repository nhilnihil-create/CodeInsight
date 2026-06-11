#include <bits/stdc++.h>
using namespace std;

signed main () {
    int h, w, n, sr, sc;
    string s, t;
    cin >> h >> w >> n >> sr >> sc >> s >> t;
 
    auto func = [&](char mi, char ma, int pos, int siz) -> bool {
        int posmi = pos, posma = pos;
        for (int i = 0; i < n; ++i) {
            if (s[i] == ma)
                posma++;
            else if (s[i] == mi)
                posmi--;
            if (posma > siz)
                return true;
            if (posmi < 1)
                return true;
            if (t[i] == ma)
                posmi = min(posmi + 1, siz);
            else if (t[i] == mi)
                posma = max(posma - 1, 1);
            if (posma > siz)
                return true;
            if (posmi < 1)
                return true;
        }
        return false;
    };
 
    bool res = false;
    res |= func('U', 'D', sr, h);
    res |= func('L', 'R', sc, w);
 
    cout << (res ? "NO" : "YES") << '\n';
}
