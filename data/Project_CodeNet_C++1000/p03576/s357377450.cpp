#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<ll, ll>;
const long double PI = acos(-1.0L);
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

const ll INF = INT64_MAX;

int n, k;

int main() {
    cin >> n >> k;
    vector<ll> xvec(n, 0);
    vector<ll> yvec(n, 0);
    for(int i = 0; i < n; ++i) cin >> xvec[i] >> yvec[i];
    vector<P> xpvec;
    vector<P> ypvec;
    for(int i = 0; i < n; ++i) {
        for(int j = i+1; j < n; ++j) {
            xpvec.emplace_back(P(xvec[i], xvec[j]));
            ypvec.emplace_back(P(yvec[i], yvec[j]));
        }
    }
    int plen = xpvec.size();

    ll ans = INF;
    for(int i = 0; i < plen; ++i) {
        for(int j = 0; j < plen; ++j) {
            if(xpvec[i].first > xpvec[i].second) swap(xpvec[i].first, xpvec[i].second);
            if(ypvec[j].first > ypvec[i].second) swap(ypvec[j].first, ypvec[j].second);
            ll llimit = xpvec[i].first, rlimit = xpvec[i].second;
            ll blimit = ypvec[j].first, ulimit = ypvec[j].second;
            int cnt = 0;
            for(int l = 0; l < n; ++l) {
                int chx = xvec[l], chy = yvec[l];
                if(chx >= llimit && chx <= rlimit && chy >= blimit && chy <= ulimit) cnt++;
            }

            if(cnt >= k) {
                ll square = (rlimit-llimit)*(ulimit-blimit);
                chmin(ans, square);
            }
        }
    }

    cout << ans << endl;
}