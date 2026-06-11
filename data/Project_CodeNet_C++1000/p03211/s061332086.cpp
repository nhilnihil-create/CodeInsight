#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

const int INF = 1001;

int main()
{
    string s;
    cin >> s;
    int mini = INF;
    rep(i, s.size() - 2) {
        mini = min(mini, abs(100 * (s[i] - '0') + 10 * (s[i + 1] - '0') + (s[i + 2] - '0') - 753));
    }
    cout << mini << endl;
    return 0;
}