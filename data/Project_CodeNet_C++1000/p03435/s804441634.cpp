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
    vector<vector<ll>> C(3, vector<ll>(3));
    rep(i,3){
        rep(j, 3){
            cin>>C[i][j];
        }
    }
    bool OK=true;
    if((C[0][0]-C[0][1])-(C[1][0]-C[1][1]))OK=false;
    if((C[1][0]-C[1][1])-(C[2][0]-C[2][1]))OK=false;
    if((C[0][1]-C[0][2])-(C[1][1]-C[1][2]))OK=false;
    if((C[1][1]-C[1][2])-(C[2][1]-C[2][2]))OK=false;
    if((C[0][0]-C[1][0])-(C[0][1]-C[1][1]))OK=false;
    if((C[0][1]-C[1][1])-(C[0][2]-C[1][2]))OK=false;
    if((C[1][0]-C[2][0])-(C[1][1]-C[2][1]))OK=false;
    if((C[1][1]-C[2][1])-(C[1][2]-C[2][2]))OK=false;
    Yes(OK);

}