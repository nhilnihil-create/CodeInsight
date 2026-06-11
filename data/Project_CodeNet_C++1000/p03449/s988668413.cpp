#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for(ll i=(a); i<(b); i++)
#define PER(i, a, b) for(ll i=(a); i>=(b); i--)
#define rep(i, n) REP(i, 0, n)
#define per(i, n) PER(i, n, 0)
#define ALL(a)  (a).begin(),(a).end()
const ll INF = 1e18+18;
const ll MAX = 200000;
const ll MOD = 1000000007;
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl;
#define YES(n) cout << ((n) ? "YES" : "NO") << endl;
static const long double pi = 3.141592653589793;


int main(){
    ll N;
    cin>>N;
    vector<vector<ll>> A(2, vector<ll>(N));
    rep(i, 2){
        rep(j, N){
            cin>>A[i][j];
        }
    }
    ll MAX=-1;
    rep(i, N){
        ll Num=0;
        rep(j, i+1){
            Num+=A[0][j];
        }
        for(ll j=i; j<N; j++){
            Num+=A[1][j];
        }
        MAX=max(MAX, Num);
    }
    cout<<MAX<<endl;
}
    