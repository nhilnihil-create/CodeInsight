#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;


int main() {
    ll n, cnt = 0;
    string s,ans;
    cin >> n;
    vector<string>ab,a, b, o;
    rep(i, n) {
        cin >> s;
        rep(i, s.size() - 1)if (s.substr(i, 2) == "AB")cnt++;
        if (s[0] == 'B' && s[s.size() -1] == 'A')ab.push_back(s);
        else if (s[s.size() - 1] == 'A')a.push_back(s);
        else if (s[0] == 'B')b.push_back(s);
        else o.push_back(s);
    }
    if (ab.size() == 0)cout << cnt + min(a.size(), b.size()) << endl;
    else if (a.size() + b.size() == 0)cout << cnt + ab.size() - 1 << endl;
    else cout << cnt + min(a.size(), b.size()) + ab.size() << endl;
    return 0;
}