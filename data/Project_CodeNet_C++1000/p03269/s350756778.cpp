#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1000111, max_log = 22, inf = 1000111222;

int p2[max_log];

vector<pair<pair<int, int>, int>> ans;
int ed[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    int L;
    cin >> L;
    p2[0] = 1;
    for (int i = 1; i < max_log; ++i) {
        p2[i] = p2[i - 1] * 2;
    }
    int n = 0;
    for (int i = 0; i < max_log; ++i) {
        if (p2[i] <= L) {
            n = i;
        }
    }
    for (int i = 0; i < n; ++i) {
        ans.push_back(MP(MP(i, i + 1), p2[n - i - 1]));
        ans.push_back(MP(MP(i, i + 1), 0));
        ed[i] = p2[n - i - 1];
    }
    L -= p2[n];
    ll have = p2[n];
    while (L > 0) {
        int mp = 0;
        for (int i = 0; i < max_log; ++i) {
            if (p2[i] <= L) {
                mp = i;
            }
        }
        if (mp == 0) {
            ans.push_back(MP(MP(0, n), have));
        } else {
            for (int i = 0; i < n; ++i) {
                if (ed[i] == p2[mp - 1]) {
                    ans.push_back(MP(MP(0, i), have));
                }
            }
        }
        have += p2[mp];
        L -= p2[mp];
    }
    cout << n + 1 << ' ' << ans.size() << endl;
    for (auto p : ans) {
        cout << p.F.F + 1 << ' ' << p.F.S + 1 << ' ' << p.S << endl;
    }
    return 0;
}


