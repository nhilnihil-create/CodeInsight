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
    ll N, C;
    cin>>N>>C;
    vector<vector<ll>> D(C, vector<ll>(C));
    vector<vector<ll>> CC(N, vector<ll>(N));
    vector<vector<ll>> Sum(3, vector<ll>(C, 0));
    rep(i, C){
        rep(j, C){
            cin>>D[i][j];
        }
    }
    rep(i, N){
        rep(j, N){
            cin>>CC[i][j];
            CC[i][j]--;
            Sum[(i+j+2)%3][CC[i][j]]++;
        }
    }
    ll Ans=INF;
    for(ll i=0; i<C; i++){
        for(ll j=0; j<C; j++){
            for(ll k=0; k<C; k++){
                if(i==j||j==k||k==i)continue;
                ll Num=0;
                rep(l, C){
                    if(i==l)continue;
                    Num+=Sum[0][l]*D[l][i];
                }
                rep(l, C){
                    if(j==l)continue;
                    Num+=Sum[1][l]*D[l][j];
                }
                rep(l, C){
                    if(k==l)continue;
                    Num+=Sum[2][l]*D[l][k];
                }
                Ans=min(Ans, Num);
            }
        }
    }
    cout<<Ans<<endl;
}