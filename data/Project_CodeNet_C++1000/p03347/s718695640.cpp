#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,k,n) for(int i=(k);i<(n);++i)
typedef long long ll;
const ll INF = 1LL<<60;
const ll MOD = 1000000007;

inline ll add(ll x, ll y) {return (x+y)%MOD;}
inline ll mul(ll x, ll y) {return (x*y)%MOD;}
inline ll sub(ll x, ll y) {
    ll res = x - y;
    if(res < 0) res += MOD;
    return res;
}

int main(){
    int N; cin >> N;
    vector<ll> A(N);
    REP(i,N) cin >> A[i];
    bool flag = true;
    if(A[0]) flag = false;
    REP(i,N-1) {
        if(A[i+1]>A[i]+1) {
            flag = false;
            break;
        }
    }
    if(!flag) cout << -1 << endl;
    else {
        A.push_back(0);
        ll ans = 0;
        REP(i,N) {
            if(A[i]>=A[i+1]) ans += A[i];
        }
        cout << ans << endl;
    }
    return 0;
}