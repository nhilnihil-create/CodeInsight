#include <bits/stdc++.h>

using namespace std;
const int N = 8e3 + 10;
bitset <N> dpx, dpy;
vector <int> vec[2];

int main()
{
    string s; cin >> s;
    int X, Y; cin >> X >> Y;
    int n = s.size(), d = 0, i = 0, dis = 0;
    while (i < n && s[i] == 'F') i++;
    int xx = i;
    for (; i < n; i ++) {
        if (s[i] == 'T') {
            if (dis > 0) vec[d].push_back(dis);
            d ^= 1, dis = 0;
        }
        else dis++;
    }
    if (dis > 0) vec[d].push_back(dis);
    int x = 0, y = 0;
    for (int i : vec[0]) x += i;
    for (int i : vec[1]) y += i;
    dpx[x] = 1;
    dpy[y] = 1;
    for (int i : vec[0]) dpx |= (dpx >> (i * 2));
    for (int i : vec[1]) dpy |= (dpy >> (i * 2));
    int ans = dpx[abs(X - xx)] & dpy[abs(Y)];
    cout << (ans ? "Yes\n" : "No\n");

    return 0;
}
