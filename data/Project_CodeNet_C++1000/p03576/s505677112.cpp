#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

typedef pair<ll, ll> p;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    vector<p> xy(N);

    for(int i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;
        xy[i] = make_pair(x, y);
    }

    sort(xy.begin(), xy.end());

    ll ans = 4000000000000000005;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            ll y1 = xy[i].second;
            ll x1 = xy[j].first;
            for(int k = 0; k < N; k++) {
                ll y2 = xy[k].second;
                if(y1 > y2) continue;
                ll x2;
                int c = 0;
                for(int l = j; l < N; l++) {
                    if(y1 <= xy[l].second && xy[l].second <= y2) {
                        c++;
                        if(c == K) {
                            x2 = xy[l].first;
                            break;
                        }
                    }
                }
                if(c < K) continue;
                ans = min(ans, (x2 - x1) * (y2 - y1));
            }
        }
    }

    cout << ans << endl;
}