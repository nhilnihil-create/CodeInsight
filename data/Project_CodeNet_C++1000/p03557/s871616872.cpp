#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#include <map>
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using Graph = vector<vector<int>>;


template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}




int main() {
    ll n;
    cin >> n;
    vector<ll> A(n);
    vector<ll> B(n);
    vector<ll> C(n);
    vector<ll> a;
    vector<ll> b;
    vector<ll> c;
    REP(i,n){
        cin >> A[i];
    }
    REP(i,n){
        cin >> B[i];
    }
    REP(i,n){
        cin >> C[i];
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    sort(C.begin(),C.end());
    // REP(i, n){
    //     if(i >0){
    //         if(a[a.size()-1] == A[i]) continue;
    //     }
    //     a.push_back(A[i]);
    // }
    // REP(i, n){
    //     if(i >0){
    //         if(b[b.size()-1] == B[i]) continue;
    //     }
    //     b.push_back(B[i]);
    // }
    // REP(i, n){
    //     if(i >0){
    //         if(c[c.size()-1] == C[i]) continue;
    //     }
    //     c.push_back(C[i]);
    // }
    ll ans = 0;
    REP(i, B.size()){
        //cout << "b= " << B[i] << endl;
        ll num_a = (lower_bound(A.begin(),A.end(),B[i]) - A.begin());
        //cout << num_a << endl;
        ll num_c = C.size() - (upper_bound(C.begin(),C.end(),B[i]) - C.begin()) ;
        //cout << num_c << endl;
        ans += num_a * num_c;
    }
    cout << fixed << ans << endl;

}

