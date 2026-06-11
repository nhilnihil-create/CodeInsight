//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;



int main() {
    int n;
    cin >> n;
    vector<P> red(n), blue(n);
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        red[i] = P(a, b);
    }
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        blue[i] = P(a, b);
    }

    sort(all(red));
    sort(all(blue));
    vector<bool> used(n);

    rep(i, n) {
        vector<P>::iterator itr = lower_bound(all(red), blue[i]);
        int ma=-1;
        int x;
        itr--;
        for(;itr >= red.begin(); --itr) {
            if(!used[distance(red.begin(), itr)] && blue[i].second > (*itr).second) {
                if(ma < (*itr).second) {
                    ma = (*itr).second;
                    x = distance(red.begin(), itr);
                }
            }
        }
        if(ma != -1) {
            used[x] = true;
        }
    }

    int ans = 0;
    rep(i, n) {
        if(used[i]) {
            ans++;
        }
    }

    cout << ans << endl;
}