//----------------------------------------------------------------------
#include <bits/stdc++.h>
#include <sched.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
//----------------------------------------------------------------------

using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main(void) {
    int n; cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    vector<int> h(n);

    int sugestind;
    rep(i, n) {
        cin >> x[i] >> y[i] >> h[i];
        if(h[i] != 0) {
            sugestind = i;
        }
    }

    rep(i,101)
    rep(j,101) {
        bool flag = true;
        int ix = i;
        int iy = j;
        int sggesth = h[sugestind]  + abs(x[sugestind] - ix) + abs(y[sugestind] - iy);
        rep(i,n) {
            int dx = abs(x[i]-ix);
            int dy = abs(y[i]-iy);
            int tmph = max(sggesth - dx - dy, 0);
            if(tmph != h[i]) {
                flag = false;
            }
        }
        if(flag) {
            cout << ix << " " << iy << " " << sggesth << endl;
            return 0;
        }
    }
    return 0;
}
