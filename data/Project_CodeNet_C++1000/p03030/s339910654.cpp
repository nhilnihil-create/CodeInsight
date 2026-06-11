#include <bits/stdc++.h>
typedef long long lint;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

int main() {
    int n; cin >> n;
    pair<string, int> sp[100];
    rep(i,n) {
        cin >> sp[i].first >> sp[i].second;
        sp[i].second = sp[i].second * 1000 + (i+1);
    }
    sort(sp,sp+n);
    int pre = 0;
    string pres = sp[0].first;
    rep(i,n) {
        if (sp[i].first != pres) {
            sort(sp+pre, sp+i, greater<pair<string, int>>());
            pre = i;
            pres = sp[i].first;
        }
    }
    sort(sp+pre, sp+n, greater<pair<string, int>>());
    rep(i,n) {
        cout << sp[i].second % 1000 << endl;
    }
}