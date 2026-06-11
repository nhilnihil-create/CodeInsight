#include<bits/stdc++.h>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define dump(a) (cerr << #a << "=" << (a) << endl)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    vector<ll> a(N+1);
    rep(i, N) cin >> a[i+1];

    vector<ll>bits;
    rep(i, N) a[i+1] += a[i];
    rep(i, N) {
        for (int j = i; j < N; ++j) {
            ll sum = a[j+1] - a[i];
            bits.push_back(sum);
        }
    }

    sort(bits.rbegin(), bits.rend());

    vector<ll> now = bits;
    for (ll b = 63; b >= 0; --b) {
        vector<ll> next;
        for (auto i : now) {
            if (i & (1LL << b)) next.push_back(i);
        }

        if (next.size() >= K) now = next;
    }

    ll ans = now[0];
    rep(i, K) ans &= now[i];
    cout << ans << endl;


}