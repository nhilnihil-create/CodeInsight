#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222;

string s, t;
int h, w, n, si, sj;
string ss, tt;

void inv(string& s) {
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'D') {
            s[i] = 'R';
        }
        if (s[i] == 'U') {
            s[i] = 'L';
        }
    }
}

bool solve(string s, string t, int pos, int mx) {
    int l = -1, r = mx;
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] == 'L') {
            ++l;
        }
        if (s[i] == 'R') {
            --r;
        }
        if (t[i] == 'L') {
            ++r;
        }
        if (t[i] == 'R') {
            --l;
        }
        l = max(-1, l);
        r = min(mx, r);
        if (s[i] == 'R') {
            r = min(mx - 1, r);
        }
        if (s[i] == 'L') {
            l = max(0, l);
        }
        if (r - l <= 1) return true;
    }
    if (pos <= l || pos >= r) return true;
    return false;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> h >> w >> n;
    cin >> si >> sj;
    --si, --sj;
    cin >> s;
    cin >> t;
    ss = s;
    tt = t;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'U' || s[i] == 'D') {
            ss[i] = '.';
        }
        if (t[i] == 'U' || t[i] == 'D') {
            tt[i] = '.';
        }
    }
    if (solve(ss, tt, sj, w)) {
        cout << "NO" << endl;
        return 0;
    }
    ss = s;
    tt = t;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'L' || s[i] == 'R') {
            ss[i] = '.';
        }
        if (t[i] == 'L' || t[i] == 'R') {
            tt[i] = '.';
        }
    }
    inv(ss);
    inv(tt);
    if (solve(ss, tt, si, h)) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;

    return 0;
}


