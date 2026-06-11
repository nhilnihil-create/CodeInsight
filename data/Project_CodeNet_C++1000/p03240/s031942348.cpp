#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> h(101, vector<int>(101, 0));
    vector<P> xy;
    rep(i, n){
        int x, y, h1;
        cin >> x >> y>> h1;
        h[x][y] = h1;
        xy.push_back(P(x, y));
    }
    ll cx, cy, hans;
    bool flag = false;
    rep(i, 101){
        if(flag) break;
        rep(j, 101){
            if(flag) break;
            cx = i; cy = j;
            for(P w:xy){
                int x0 = w.first, y0 = w.second;
                hans = h[x0][y0];
                hans += abs(cx - x0);
                hans += abs(cy - y0);
                if(hans == 0)continue;
                bool ok = true;
                for(P z:xy){
                    ll memo = hans;
                    memo -= abs(z.first - cx);
                    memo -= abs(z.second - cy);
                    memo = max(memo, (ll)0);
                    if(memo != h[z.first][z.second]) {
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    flag = true;
                    break;
                }
                if(h[x0][y0] != 0) break;
            }
        }
    }
    cout << cx << " " << cy << " " << hans << endl;
    return 0;
}