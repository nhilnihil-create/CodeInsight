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

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << ":" << #x << " = " << (x) << endl;
#else
#define dbg
#endif

#pragma endregion Macros

int main()
{
    int N,K;
    cin >> N >> K;
    vector<ll> left, right;
    left.push_back(0);
    right.push_back(0);
    
    rep(i,N){
        ll x;
        cin >> x;
        if (x == 0) {
            K--; // 0はなかったことにする
        }else if(x > 0){
            right.push_back(x);
        }else{
            left.push_back(-x);
        }
    }

    if(K==0) {
        cout << 0 << endl;
        return 0;
    }

    sort(left.begin(), left.end());
    int NL = left.size();
    int NR = right.size();

    ll ans = 100100100100100100LL;

    //左に行って引き返して右
    for(int i=0; i<min(K, NL); i++){
        if (K - i >= NR) continue;

        ll res;
        res = left[i] * 2;
        res += right[max(0, K - i)];

        chmin(ans, res);
    }

    //右に行って引き返して左
    for(int i=0;i<min(K,NR);i++){
        if (K - i >= NL) continue;
        ll res;
        res = right[i]*2;
        res += left[max(0, K - i)];

        chmin(ans, res);
    }

    cout << ans << endl;
}
