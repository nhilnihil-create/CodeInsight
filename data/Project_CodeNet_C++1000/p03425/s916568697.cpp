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
    ll N;
    cin>>N;
    vector<string> S(N);
    vector<ll> M(5);

    rep(i, N){
        cin>>S[i];
        if(S[i].at(0)=='M')M[0]++;
        if(S[i].at(0)=='A')M[1]++;
        if(S[i].at(0)=='R')M[2]++;
        if(S[i].at(0)=='C')M[3]++;
        if(S[i].at(0)=='H')M[4]++;
    }
    ll Ans=0;
    rep(i, 5){
        for(ll j=i+1; j<5; j++){
            for(ll k=j+1; k<5; k++){
                Ans+=M[i]*M[j]*M[k];
            }
        }
    }
    cout<<Ans<<endl;
}