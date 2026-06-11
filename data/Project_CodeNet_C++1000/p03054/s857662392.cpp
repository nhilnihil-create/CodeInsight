#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(int i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(int i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define uniq(x) (x).erase(unique((x).begin(), (x).end()), (x).end())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // std::ifstream in("input.txt");
    // std::cin.rdbuf(in.rdbuf());
    int h, w, n;
    cin >> h >> w >> n;
    int sr, sc;
    cin >> sr >> sc;
    sr--; sc--;
    string s, t;
    cin >> s >> t;
    int lr = 0, lc = 0, rr = h - 1, rc = w - 1;
    rrep(i, n) {
        if (t[i] == 'U') rr++;
        else if (t[i] == 'R') lc--;
        else if (t[i] == 'D') lr--;
        else if (t[i] == 'L') rc++;
        if ((rr < lr) || (rc < lc)) {
            cout << "NO" << endl;
            return 0;
        }
        lr = max(0, min(h - 1, lr));
        lc = max(0, min(w - 1, lc));
        rr = max(0, min(h - 1, rr));
        rc = max(0, min(w - 1, rc));
        if (s[i] == 'U') lr++;
        else if (s[i] == 'R') rc--;
        else if (s[i] == 'D') rr--;
        else if (s[i] == 'L') lc++;
        if ((rr < lr) || (rc < lc)) {
            cout << "NO" << endl;
            return 0;
        }
        lr = max(0, min(h - 1, lr));
        lc = max(0, min(w - 1, lc));
        rr = max(0, min(h - 1, rr));
        rc = max(0, min(w - 1, rc));
        // printf("(%d, %d), (%d, %d)\n", lr, lc, rr, rc);
    }
    if ((sr >= lr) && (sr <= rr) && (sc >= lc) && (sc <= rc)) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}
