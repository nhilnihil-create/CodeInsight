#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

string S, T;
int main() {
    // cout << 'd' - 'a' << endl;
    // return 0;

    cin >> S >> T;
    map<int, int> s_mp, e_mp;
    rep(i, 26) {
        s_mp[i] = -1;
        e_mp[i] = -1;
    }

    string ans = "Yes";
    for (int i = 0; i < S.size(); i++) {
        int before = S[i] - 'a';
        int after = T[i] - 'a';

        // cout << "i: " << i << " " << endl;
        // cout << s_mp[before] << " " << after << endl;
        // cout << e_mp[after] << " " << before << endl;
        if (s_mp[before] == -1 && e_mp[after] == -1) {
            s_mp[before] = after;
            e_mp[after] = before;
            continue;
        } 

        if (s_mp[before] != after || e_mp[after] != before) {
            ans = "No";
            break;
        }
    }

    // // S を変換させてTになるかどうかを見る
    // for (auto m : mp) {
    //     cout << m.first << " " << m.second << endl;
    //     cout << (char)('a' + m.first) << " " << (char)('a' + m.second) << endl;
    // }

    cout << ans << endl;
}