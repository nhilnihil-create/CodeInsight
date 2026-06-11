#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main() {
    string s, t;
    cin >> s >> t;

    vector<set<char>> temp1(26);
    vector<set<char>> temp2(26);

    rep(i, s.size()) {
        temp1[s[i] - 'a'].insert(t[i]);
        temp2[t[i] - 'a'].insert(s[i]);
    }

    rep(i, 26) {
        if(temp1[i].size() > 1 || temp2[i].size() > 1) {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}