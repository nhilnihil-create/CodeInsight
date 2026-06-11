#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 1e5 + 5;
const ll INF = 9223372036854775807;
const int MOD = 1e9 + 7;

int main(){
    int N, K;
    cin >> N >> K;

    vector<P> D;
    rep(i, N) {
        int x, y;
        cin >> x >> y;
        D.emplace_back(x, y);
    }

    sort(D.begin(), D.end());

    ll ans = INF;

    rep(i, N)rep(j, N) {
        int y1 = min(D[i].second, D[j].second);
        int y2 = max(D[i].second, D[j].second);

        int r = 0, cnt = 0;
        rep(l, N) {
            while(r < N && cnt < K) {
                if (y1 <= D[r].second && D[r].second <= y2) cnt++;
                r++;
            }

            if (cnt == K) ans = min(ans, (ll)(D[r-1].first - D[l].first) * (y2 - y1));
            
            if (l == r) r++;
            else if (y1 <= D[l].second && D[l].second <= y2) cnt--;
        }
    }

    cout << ans << endl;
}