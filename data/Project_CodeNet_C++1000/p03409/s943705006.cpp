#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll N;

int main() {
    cin >> N;
    vector<P> red(N);
    vector<P> blue(N);

    rep(i, N) {
        ll a, b;
        cin >> a >> b;
        red[i] = P(a, b);    
    }
    sort(red.begin(), red.end());

    rep(i, N) {
        ll c, d;
        cin >> c >> d;
        blue[i] = P(c, d);    
    }
    sort(blue.begin(), blue.end());

    ll cnt = 0;
    for (ll i = 0; i < blue.size(); i++) {

        ll red_idx = -1;
        ll red_y = -1;
        for (ll j = 0; j < red.size(); j++) {
            if (blue[i].first > red[j].first && blue[i].second > red[j].second) {
                if (red_y < red[j].second) {
                    red_y = red[j].second;
                    red_idx = j;
                }
            }
        } 

        // cout << red_idx << endl;
        if (red_idx != -1) {
            red.erase(red.begin() + red_idx);
            cnt++;
        }
    }

    cout << cnt << endl;
}