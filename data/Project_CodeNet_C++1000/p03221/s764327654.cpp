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
    ll N, M;
    cin>>N>>M;
    vector<ll> P(M), Y(M);
    vector<priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>>  Q(N+1);
    rep(i, M){
        cin>>P[i]>>Y[i];
        Q[P[i]].push(make_pair(Y[i], i));
    }
    vector<ll> R(M);
    rep(i, N+1){
        ll T=1;
        while(Q[i].size()){
            pair<ll, ll> S=Q[i].top();
            Q[i].pop();
            R[S.second]=T;
            T++;
        }
    }
    rep(i, M){
        ll Ke, Ta;
        Ke=0;
        Ta=0;
        while(pow(10, Ke)<=P[i]){
            Ke++;
        }
        while(pow(10, Ta)<=R[i]){
            Ta++;
        }
        rep(j, 6-Ke)cout<<0;
        cout<<P[i];
        rep(j, 6-Ta)cout<<0;
        cout<<R[i]<<endl;

    }
}
     