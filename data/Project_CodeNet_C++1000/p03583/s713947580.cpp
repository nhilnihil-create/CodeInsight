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



int main(){
    ll N;
    cin>>N;
    for(ll h=1; h<=3500; h++){
        for(ll n=1; n<=3500; n++){
            ll A=N*h*n;
            ll B=4*h*n-N*h-N*n;
            if(B>0&&A%B==0){
                cout<<A/B<<" "<<n<<" "<<h<<endl;
                return 0;
            }
        }
    }
}