#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define pb push_back
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forrn(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define PYMOD(a, m) ((((a) % (m)) + (m)) % (m))
#define all(v) v.begin(), v.end()
#define mp make_pair
#define ff first
#define ss second

const int mod = 1e9 + 7;

struct query {
    char t;
    char d;
};

enum result {
    LEFT,
    STAY,
    RIGHT
};

result where(int i, const string& s, const vector<query>& qs) {
    for (const query& q : qs) {
        if (q.t == s[i]) {
            if (q.d == 'L')
                i--;
            else
                i++;
        }
        if (i < 0)
            return LEFT;
        else if (i >= (int)s.size())
            return RIGHT;
    }
    return STAY;
}

int main() {
    // Code here:

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    vector<query> qs(q);
    for (query& qu : qs)
        cin >> qu.t >> qu.d;

    int ans = n;

    int lt = -1, rt = n - 1;
    while (lt < rt - 1) {
        int mid = (lt + rt) / 2;
        if (where(mid, s, qs) == LEFT)
            lt = mid;
        else
            rt = mid;
    }
    cerr << "last LEFT: " << lt << endl;
    ans -= rt;

    rt = n;
    while (lt < rt - 1) {
        int mid = (lt + rt) / 2;
        if (where(mid, s, qs) == STAY)
            lt = mid;
        else
            rt = mid;
    }
    cerr << "first RIGHT: " << rt << endl;
    ans -= n - rt;

    cout << ans << endl;

    return 0;
}
