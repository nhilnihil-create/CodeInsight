//解説見た
#include <bits/stdc++.h>
typedef long long lint;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

// [  [@] ]
// [  [  ] [] ]
// 1 2 3 4 7
// 5 6 7 8 9

// 1 1 1 1 2 2 2 3 3 4
// 2 3 3 4 4 4 5 5 5 5

// 1 2 2 2 1
// 123443321
int main() {
    int n,m; cin >> n >> m;
    pair<int,int> ba[100000]; rep(i,m) cin >> ba[i].second >> ba[i].first;
    sort(ba, ba+m);
    int prev = -1;
    int ans = 0;
    rep(i,m) {
        if (ba[i].second > prev) {
            ans ++;
            prev = ba[i].first-1;
        }
    } 
    cout << ans << endl;

}