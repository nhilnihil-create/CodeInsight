#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

const ll mod = 1000000007;

int main() {
    int h, w, cnt;
    cin >> h >> w;
    vector<vector<int>> field(h, vector<int>(w));
    vector<i_i> ans;

    rep(i, h){
        rep(j, w){
            cin >> field[i][j];
        }
    }
    bool increaseNext = false;
    cnt = 1;
    rep(hi, h){
        rep(wi, w){
            int chi,cwi;
            chi = hi;
            cwi = wi;
            if(hi % 2 == 1){
                cwi = w - 1 - wi;
            }
            if(increaseNext){
                field[chi][cwi]++;
                ans.push_back(make_pair(chi,cwi));
                increaseNext = false;
            }
            if(cnt == h * w) break;

            if(field[chi][cwi] % 2 == 1){
                field[chi][cwi]--;
                increaseNext = true;
                ans.push_back(make_pair(chi,cwi));
            }
            cnt++;
        }
    }
    int k = ans.size() / 2;
    cout << k << endl;
    rep(i, k){
        cout << ans[2 * i].first + 1 << " " << ans[2 * i].second + 1 << " " << ans[2 * i + 1].first + 1 << " " << ans[2 * i + 1].second + 1 << endl;
    }
    return 0;
}
