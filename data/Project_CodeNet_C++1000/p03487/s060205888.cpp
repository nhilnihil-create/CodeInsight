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
    ll N;
    cin>>N;
    vector<ll> A(N);
    map<ll, ll> M;
    set<ll> X;
    rep(i, N){
        cin>>A[i];
        X.insert(A[i]);
        M[A[i]]++;
    }
    ll Ans=0;
    while(!(X.empty())){
      	//cout<<"!";
        auto K=X.begin();
        X.erase(K);
        ll Y=M[*K];
        if(M[*K]-*K<0){
            Ans+=M[*K];
        }
        else{
            Ans+=M[*K]-*K;
        }
      	//cout<<Ans<<endl;
    }
    cout<<Ans<<endl;

}
     