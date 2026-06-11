#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

void judge(int &i, unordered_map<char, char> &map, string &S1, string &S2, string &ans) {
    if (map.count(S1.at(i)) == 1 && map[S1.at(i)] != S2.at(i)) {
        ans = "No";
    } else map[S1.at(i)] = S2.at(i);
}

int main() {
    string S, T;
    cin >> S >> T;
    unordered_map<char, char> Smap, Tmap;
    string ans = "Yes";
    rep(i,S.size()) {
        judge(i, Smap, S, T, ans);
        judge(i, Tmap, T, S, ans);
    }
    cout << ans << endl;
}
