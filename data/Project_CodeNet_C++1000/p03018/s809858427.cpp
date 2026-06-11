#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    vector<char> trans;
    char prev = '#';
    rep(i, s.size()) {
        if (prev == 'B' && s[i] == 'C')
            trans[trans.size() - 1] = 'D';
        else
            trans.push_back(s[i]);
        prev = s[i];
    }

    bool judge = 0;
    ll cnt = 0;
    ll sum = 0;
    rep(i, trans.size()) {
        if (!judge && trans[i] == 'A')
            judge = 1, cnt++;
        else if (judge) {
            if (trans[i] == 'A')
                cnt++;
            else if (trans[i] == 'D')
                sum += cnt;
            else
                judge = 0, cnt = 0;
        }
    }

    cout << sum << endl;
}
