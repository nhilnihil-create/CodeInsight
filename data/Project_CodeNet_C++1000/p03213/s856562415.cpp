#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int ans = 0;

void an(){
    ans++;
}


vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({a, ex});
    }

    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}

int main() {
    ll N;
    cin >> N;
    ll M;
    vector<ll>pfs(N+1);
    for (ll i=1; i<=N; i++){
        vector<pair<ll, ll>>curr_pf;
        curr_pf = prime_factorize(i);
        for (ll j=0; j<curr_pf.size(); j++){
            pair<ll, ll>pr;
            pr = curr_pf[j];
            pfs[pr.first] += pr.second;

        }
    }
    int c2, c4, c14, c24, c74;
    c2 = c4 = c14 = c24 = c74 = 0;
    for (int i=0; i<N+1; i++){
        if (pfs[i] >= 2)c2++;
        if (pfs[i] >= 4)c4++;
        if (pfs[i] >= 14)c14++;
        if (pfs[i] >= 24)c24++;
        if (pfs[i] >= 74)c74++;
    }

    ans += (c4 * (c4-1) * (c2-2)) /2;
    ans += c14 * (c4-1);
    ans += c24 * (c2 - 1);
    ans += c74;

    cout << ans << endl;
}