#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)

int main() {
    int n; cin >> n;
    vector<vector<int64_t>> xyh(n,vector<int64_t>(3));
    rep(i,n){
        rep(j,3){
            cin >> xyh[i][j];
        }
    }
    int64_t ansx, ansy, ansh;
    bool bk = false;
    rep(cx,101){
        rep(cy,101){
            int64_t h = -1;
            int64_t maxh = 1e10;
            bool b = true;
            rep(i,n){
                int xi = xyh[i][0];
                int yi = xyh[i][1];
                int hi = xyh[i][2];

                if(hi == 0){
                    maxh = min(maxh,(int64_t)(abs(xi-cx)+abs(yi-cy)));
                    if(h > maxh){
                        b = false;
                        break;
                    }
                }
                else{
                    int64_t chi = hi + abs(xi-cx) + abs(yi-cy);
                    if(h > 0 && chi != h){
                        b = false;
                        break;
                    }
                    if(h == -1) h = chi;
                    if(h > maxh){
                        b = false;
                        break;
                    }
                }
            }
            if(b){
                if(h < 1) h = 1;
                if(h > maxh){
                    continue;
                }
                ansx = cx; ansy = cy; ansh = h;
                bk = true;
                break;
            }
        }
        if(bk) break;
    }

    cout << ansx << " " << ansy << " " << ansh << endl;
}
