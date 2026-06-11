#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#pragma region Macros
#define FOR(i, m, n) for (ll i = (ll)(m); i < (ll)(n); i++)
#define rep(i, n) FOR(i, 0, n)

template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template <class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

template <class T> string join(const T &v, const string delim = ",")
{
    if (v.empty())
        return "";

    ostringstream res;
    res << v[0];
    for (int i = 1; i < v.size(); i++)
    {
        res << delim << v[i];
    }
    return res.str();
}

#pragma endregion Macros

int main()
{
    int H,W,D;
    cin >> H >> W >> D;
    vector<vector<int>> A(H, vector<int>(W));
    rep(i, H) rep(j, W) cin >> A[i][j];

    vector<int> x(H * W + 1), y(H * W + 1);
    rep(i,H) rep(j,W){
        x[A[i][j]] = j;
        y[A[i][j]] = i;
    }

    vector<ll> d(H * W + 1); // d[i] : iに移動するまでにかかるコスト
    for(int i=1;i<=H*W;i++){
        if (i < D) d[i] = 0;
        else{
            int cx = x[i];
            int cy = y[i];
            int px = x[i-D];
            int py = y[i - D];
            d[i] = d[i - D] + abs(cx - px) + abs(cy - py);
        }
    }

    int Q;
    cin >> Q;
    rep(q,Q){
        int L,R;
        cin >> L >> R;

        cout << d[R] - d[L] << endl;
    }
}
