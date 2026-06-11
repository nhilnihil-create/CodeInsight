

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
    ll N, M;
    cin >> N >> M;
    ll A[N];
    ll S[N+1];
    S[0] = 0;
    rep(i, N) {
        cin >> A[i];
        S[i+1] = A[i] + S[i];
        S[i+1] %= M;
    }

    map<ll, ll> m;
    REP(i,1, N+1) {
        if (!m.count(S[i])) {
            m.insert(make_pair(S[i], 1));
        } else {
            m[S[i]]++;
//            cout << S[i] << " " << m[S[i]] << endl;
        }
    }
    ll ans = 0;
    for (auto i = m.begin(); i != m.end(); ++i) {
//        cout << i->second << endl;
        if (i->first != 0) {
            ans += (i->second * (i->second - 1))/2;
        } else {
            ans += (i->second * (i->second - 1))/2 + i->second;
        }
    }
    cout << ans << endl;


}