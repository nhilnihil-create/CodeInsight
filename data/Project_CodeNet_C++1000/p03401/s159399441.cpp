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
    vector<ll> A(N);
    ll Sum=0;
    rep(i, N){
        cin>>A[i];
        if(i==0){
            Sum+=abs(A[i]);
        }
        else{
            Sum+=abs(A[i]-A[i-1]);
        }
    }
    Sum+=abs(A[N-1]);
    cout<<Sum-abs(A[0])-abs(A[1]-A[0])+abs(A[1])<<endl;
    rep(i, N-2){
        cout<<Sum-abs(A[i+1]-A[i])-abs(A[i+2]-A[i+1])+abs(A[i]-A[i+2])<<endl;
    }
    cout<<Sum-abs(A[N-1])-abs(A[N-1]-A[N-2])+abs(A[N-2])<<endl;
}