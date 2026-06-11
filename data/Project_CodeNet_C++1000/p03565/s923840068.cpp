#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long

string S, T;
vector<string> v;

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> S >> T;
    rep(i, S.size()-T.size()+1) {
        bool flag = true;
        rep(j, T.size()) {
            if (S[i+j]=='?') continue;
            else flag &= S[i+j]==T[j];
        }
        if (flag) {
            string s = "";
            rep(j, S.size()) {
                if (i<=j && j<i+T.size()) s += T[j-i];
                else {
                    if (S[j]=='?') s += "a";
                    else s += S[j];
                }
            }
            v.pb(s);
        }
    }
    sort(v.begin(), v.end());
    if (v.size()==0) cout << "UNRESTORABLE" << endl;
    else cout << v[0] << endl;
}