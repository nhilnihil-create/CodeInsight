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
    ll A, B;
    cin>>A>>B;
    vector<vector<ll>> X(100, vector<ll>(100, 0));
    rep(i, 50){
        rep(j, 100){
            X[i][j]=1;
        }
    }
    A--; B--;
    rep(i, 50){
        rep(j, 100){
            if(i%2&&j%2){
              	if(A==0)break;
                X[i][j]=0;
                A--;
            }
        }
        if(A==0)break;
    }
    for(ll i=99; i>=50; i--){
        rep(j, 100){
            if(i%2&&j%2){
              	if(B==0)break;
                X[i][j]=1;
                B--;
            }
        }
      	if(B==0)break;
    }
  	cout<<100<<" "<<100<<endl;
    rep(i, 100){
        rep(j, 100){
            if(X[i][j]==0)cout<<'.';
            if(X[i][j]==1)cout<<'#';
        }
        cout<<endl;
    }
}