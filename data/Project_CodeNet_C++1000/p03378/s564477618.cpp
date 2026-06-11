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
static const double pi = 3.141592653589793;



int main(){
    ll N, M, X;
    cin>>N>>M>>X;
    vector<ll> A(M, 0);
    ll mae=0;
    ll ushiro=0;
    rep(i, M){
        cin>>A[i];
        if(A[i]<X)mae++;
        if(A[i]>X)ushiro++;
    }
    cout<<min(mae, ushiro)<<endl;
}