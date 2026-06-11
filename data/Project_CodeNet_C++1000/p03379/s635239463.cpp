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
    vector<ll> X(N), Y(N);
    rep(i, N){
        ll j;
        cin>>j;
        X[i]=j;
        Y[i]=j;
    }
    sort(ALL(Y));
    ll A=Y[N/2-1];
    ll B=Y[N/2];
    rep(i, N){
        if(X[i]==A){
            cout<<B<<endl;
        }
        else if(X[i]==B){
            cout<<A<<endl;
        }
        else{
            if(X[i]>A){
                cout<<A<<endl;

            }
            else{
                cout<<B<<endl;
            }
        }
    }
}