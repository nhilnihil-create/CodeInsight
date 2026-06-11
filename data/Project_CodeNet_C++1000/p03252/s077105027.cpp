#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long
typedef pair<int, int> P;
//typedef tuple<int, int, int> T;

string S, T;

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> S >> T;
    map<int, set<int>> m1;
    bool flag = true;
    rep(i, S.size()) {
        m1[S[i]].insert(T[i]);
        if (m1[S[i]].size()>=2) flag = false;
    }
    map<int, set<int>> m2;
    rep(i, T.size()) {
        m2[T[i]].insert(S[i]);
        if (m2[T[i]].size()>=2) flag = false;
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}