#include <bits/stdc++.h>
using namespace std;

// 2D-vector
// vector<vector<int>> vec_2D(h, vector<int>(w, 0));

typedef long lint;
typedef long long llint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const ll INF = 1<<21;
// static const ll MOD = 1e9 + 7;

bool compPair(const pair<int, int>& arg1, const pair<int, int>& arg2) { return arg1.first > arg2.first; }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }


int main(void) {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> lr(n+1, vector<int>(n+1, 0));
    int ltmp, rtmp;
    for(int im=0;im<m;im++) {
        cin >> ltmp >> rtmp;
        lr.at(ltmp).at(rtmp)++;
    }
    for(int il=1;il<=n;il++) {
        for(int ir=1;ir<=n;ir++) {
            lr.at(il).at(ir) += lr.at(il).at(ir-1);
        }
    }
    for(int il=1;il<=n;il++) {
        for(int ir=1;ir<=n;ir++) {
            lr.at(il).at(ir) += lr.at(il-1).at(ir);
        }
    }

    int ans, ptmp, qtmp;
    for(int iq=0;iq<q;iq++) {
        cin >> ptmp >> qtmp;
        ans = lr.at(qtmp).at(qtmp)+lr.at(ptmp-1).at(ptmp-1);
        ans -= lr.at(qtmp).at(ptmp-1)+lr.at(ptmp-1).at(qtmp);
        cout << ans << endl;
    }
    return 0;
}
