#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;

int main()
{
    string n;
    cin >> n;
    if(n.size() == 1) {
        cout << n[0] - '0' << endl;
        return 0;
    }
    bool t = true;
    repl(i, 1, n.size()) {
        if(n[i] != '9') t = false;
    }
    if(t) cout << 9 * (n.size() - 1) + (n[0] - '0') << endl;
    else {
        cout << (n[0] - '0' - 1) + 9 * (n.size() - 1) << endl;
    }
    return 0;
}
