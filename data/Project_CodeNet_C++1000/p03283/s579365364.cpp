//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;
using ll = int64_t;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    int n, m, Q;
    cin >> n >> m >> Q;
    vi l(m), r(m);
    rep(i, m) {
        cin >> l[i] >> r[i];
        --l[i];
        --r[i];
    }
    vi p(Q), q(Q);
    rep(i, Q) {
        cin >> p[i] >> q[i];
        --p[i];
        --q[i];
    }

    vvi hyou(n, vi(n));
    rep(i, m) {
        hyou[l[i]][r[i]]++;
    }
    /*rep(i, n) {
        rep(j, n) {
            cout << hyou[i][j] << ' ';
        }
        cout << endl;
    }*/


    vvi sum(n, vi(n));
    rep(j, n) {
        for(int i = j; i >= 0; --i) {
            if(i == j) {
                sum[i][j] = hyou[i][j];
            } else if(i+1 == j) {
                sum[i][j] = sum[i+1][j] + sum[i][i] + hyou[i][j];
            } else {
                sum[i][j] = sum[i+1][j] + sum[i][j-1] + hyou[i][j] - sum[i+1][j-1];
            }
        }
    }

    //cout << endl;

    /*rep(i, n) {
        rep(j, n) {
            cout << sum[i][j] << ' ';
        }
        cout << endl;
    }

    cout << 99 << endl;*/

    rep(i, Q) {
        cout << sum[p[i]][q[i]] << '\n';
    }
}