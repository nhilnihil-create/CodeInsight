#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define RFOR(i,a,n) for(ll i=(ll)n-1;i >= (ll)a;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,0,n)
#define ALL(v) v.begin(), v.end()
#define bra(first,second) '(' << first << ',' << second << ')'
//constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
ll INF = 6001001001001001001;
long double EPS = 1e-6;
long double PI = 3.141592653589793238;
template<typename T>
void remove(std::vector<T>& vector, unsigned int index){
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<ll>>;

int main(){
    ll K;
    cin >> K;
    vector<ll> A(K);
    rep(i,K) cin >> A[i];
    if(A[K-1] != 2){
        cout << -1 << endl;
        return 0;
    }
    ll M = 3,m = 2;
    rrep(i,K-1){
        if(M < A[i] || M < m){
            cout << -1 << endl;
            return 0;
        }
        M = (M / A[i]) * A[i] + A[i] - 1;
        m = ((m + A[i] - 1) / A[i]) * A[i];
    }
    if(M < m){
        cout << -1 << endl;
        return 0;
    }
    cout << m << ' ' << M << endl;
}
