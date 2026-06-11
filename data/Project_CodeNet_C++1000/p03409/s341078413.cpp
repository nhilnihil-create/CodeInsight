#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

int main(){
    int n;
    cin >> n;
    vector<P> ba(n), cd(n);
    // 赤い点 左下
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        ba[i] = P(b, a);
    }
    // 青い点 右上
    rep(i, n) {
        int c, d;
        cin >> c >> d;
        cd[i] = P(c, d);
    }
    // 青い点はx座標が小さい順(同じならy座標が小さい順)
    sort(cd.begin(), cd.end());
    // 赤い点はy座標が大きい順(同じならx座標が大きい順)
    sort(ba.rbegin(), ba.rend());

    int ans = 0;
    vector<bool> used(n, false);
    rep(i, n) {
        int blue_x = cd[i].first;
        int blue_y = cd[i].second;
        rep(j, n) {
            int red_x = ba[j].second;
            int red_y = ba[j].first;
            if (red_x < blue_x && red_y < blue_y && !used[j]) {
                ans++;
                used[j] = true;
                break;
            }
        }
    }
    cout << ans << endl;
}