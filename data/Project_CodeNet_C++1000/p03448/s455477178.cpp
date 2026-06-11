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
    ll A, B, C, X;
    cin>>A>>B>>C>>X;
    ll Ans=0;
    rep(i, A+1){
        rep(j, B+1){
            rep(k, C+1){
                if(i*500+j*100+k*50==X)Ans++;
            }
        }
    }
    cout<<Ans<<endl;
}
    