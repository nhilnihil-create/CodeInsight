#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
#define rep2(i,a,n) for (int i = a; i < n; i++)
using namespace std;
bool is_contain_base(char s) {
    return (s == 'A' || s == 'G' || s == 'C' || s == 'T');
}
int main() {
    string S; cin >> S;
    int res = 0;
    int cur = 0;
    rep(i, S.size()) {
        if (is_contain_base(S[i])) {
            cur++;
            if (cur > res) res = cur;
        } else {
            cur = 0;
        }
    }
    printf("%d\n", res);
    return 0;
}
