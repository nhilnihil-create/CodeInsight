#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const ll INF = 1e15+1;

int main(){
    int n;
    cin >> n;
    vector<int> x(n),y(n),h(n);
    rep(i,n){
        cin >> x.at(i) >> y.at(i) >> h.at(i);
    }

    int ax,ay,ah;
    rep(cx,101){
        rep(cy,101){
            int th = -1;
            bool ok_fl = true;
            ll maxh = INF;
            rep(i,n){
                int tth = h.at(i) + abs(x.at(i)-cx) + abs(y.at(i)-cy);
                if(h.at(i) == 0){
                    maxh = min(maxh,(ll)tth);
                    continue;
                }
                if(th == -1){
                    th = tth;
                }else if(th != tth) {
                    ok_fl = false;
                    break;
                }
            }
            if(th > maxh){
                ok_fl = false;
            }

            if(ok_fl){
                ax = cx;
                ay = cy;
                ah = th;
            }
        }
    }
    cout << ax << " " << ay << " " << ah << endl;
    return 0;
}