#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int cc[1001];

int main()
{
    int n, t;
    cin >> n >> t;
    rep(i, n) {
        int c, ta;
        cin >> c >> ta;
        if(ta <= t) cc[c]++;
    }
    bool x = true;
    rep(i, 1001) {
        if(x && cc[i] == 1) {
            cout << i << endl;
            x = false;
        }
    }
    if(x) cout << "TLE" << endl;
    return 0;
}