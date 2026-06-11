#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;

vector<int> A(10);
vector<int> B = {9,2,5,5,4,5,6,3,7,6};
vector<int> C(10);
vector<int> dp(10010, -1);

int calc_lr(vector<ll> &st, ull x) {
    int left = 0, right = st.size() - 1;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (st[mid] > x) right = mid;
        else left = mid;
    } 
    return left;
}

const ll MAX_ST = 2E+10 + 10;

int main() {
    int A, B, Q;
    cin >> A >> B >> Q;
  
    vector<ll> S, T, vQ;
    ll si, ti, qi;
    S.push_back(-MAX_ST);
    T.push_back(-MAX_ST);
    rep(i, A) cin >> si, S.push_back(si);
    rep(i, B) cin >> ti, T.push_back(ti);
    rep(i, Q) cin >> qi, vQ.push_back(qi);
    S.push_back(MAX_ST);
    T.push_back(MAX_ST);

    sort(S.begin(), S.end());
    sort(T.begin(), T.end());

    for (auto xi : vQ) {
        int sl, tl;
        sl = calc_lr(S, xi);
        tl = calc_lr(T, xi);

        ull ans_i;
        ull ll = max(xi - S[sl], xi - T[tl]);
        ull rr = max(S[sl+1] - xi, T[tl+1] - xi);
        ull lsrt = (xi - S[sl]) + (T[tl+1] - S[sl]);
        ull ltrs = (xi - T[tl]) + (S[sl+1] - T[tl]);
        ull rslt = (S[sl+1] - xi) + (S[sl+1] - T[tl]);
        ull rtls = (T[tl+1] - xi) + (T[tl+1] - S[sl]);
        ans_i = min({ll, rr, lsrt, ltrs, rslt, rtls});
        cout << ans_i << endl;
    }

    return 0;
}

 