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
    ll H, W, D;
    cin>>H>>W>>D;
    vector<vector<ll>> A(H, vector<ll>(W));
    map<ll, pair<ll, ll>> M;
    rep(i, H){
        rep(j, W){
            cin>>A[i][j];
            A[i][j]--;
            M[A[i][j]]=make_pair(i, j);
        }
    }
    vector<ll> Dist(H*W);
    rep(i, H*W){
        if(i-D<0){
            Dist[i]=0;
        }
        else{
            Dist[i]=Dist[i-D]+abs(M[i].first-M[i-D].first)+abs(M[i].second-M[i-D].second);
        }
      	//cout<<Dist[i]<<endl;
    }
    ll Q;
    cin>>Q;
    vector<ll> L(Q), R(Q);
    rep(i, Q){
        cin>>L[i]>>R[i];
        cout<<Dist[R[i]-1]-Dist[L[i]-1]<<endl;
    }
	
}