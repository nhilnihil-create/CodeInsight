#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < (n); ++i)
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> ab(n);
    vector<pair<int, int>> cd(n);
    rep(i, n) {
        int tmpx, tmpy;
        cin >> tmpx >> tmpy;
        ab[i] = make_pair(tmpx, tmpy);
    }
    rep(i, n) {
        int tmpx, tmpy;
        cin >> tmpx >> tmpy;
        cd[i] = make_pair(tmpx, tmpy);
    }
    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());
//    reverse(ab.begin(), ab.end());
//    reverse(cd.begin(), cd.end());
//    printf("\n");
//    rep(i, n ) cout << ab[i].first << " " << ab[i].second << endl;
//    printf("\n");
//    rep(i, n ) cout << cd[i].first << " " << cd[i].second << endl;
    int ans = 0;
    vector<bool> flgab(n, false);
    rep(i, n) {
        int tmp_num = 0;
        bool ok = false;
        rep(j, n) {
            if ( flgab[j] ) continue;
            if ( cd[i].first > ab[j].first && cd[i].second > ab[j].second ) {
                if ( !ok ) {
                    tmp_num = j;
                    ok = true;
                }
                else if ( ab[tmp_num].second < ab[j].second ) {
                    tmp_num = j;
                }
            }
        }
        if ( ok ) {
//            cout << cd[i].first << " " << cd[i].second << " " << ab[tmp_num].first << " " << ab[tmp_num].second << endl;
            ++ans;
            flgab[tmp_num] = true;
        }
    }
    cout << ans << endl;
    return 0;
}
