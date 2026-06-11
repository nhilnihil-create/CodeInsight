#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
using vi = vector<int64_t>;
using vvi = vector<vi>;
int64_t INF = 1000000007;

int main() {
    // fasten cin
    cin.tie(0);
    ios::sync_with_stdio(false);
    // implement
    int64_t n,k;
    cin >> n >> k;
    vi x(n);
    rep(i,n) cin >> x.at(i);
    vi pos, neg;
    rep(i,n){
        if(x.at(i)>=0){
            pos.push_back(x.at(i));
        }else{
            neg.push_back(x.at(i));
        }
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end(), greater<>());
    int64_t res = INF;
    // 0を跨がないパターン
    if(pos.size()>=k) res = min(res, pos.at(k-1));
    if(neg.size()>=k) res = min(res, -neg.at(k-1));
    // 0を跨ぐパターン(i: 折り返しのindex)
    rep(i,k){
        if(i>=pos.size()) continue;
        if(k-2-i>=neg.size()) continue;
        int64_t resPos = 2*pos.at(i) - neg.at(k-2-i);
        int64_t resNeg = pos.at(i) - 2*neg.at(k-2-i);
        int64_t tmpRes = min(resPos, resNeg);
        res = min(res, tmpRes);
    }
    cout << res << endl;
}