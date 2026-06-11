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
   ll N, K;
    cin>>N>>K;
    vector<ll> A(N);
    vector<ll> B(41, 0);
    rep(i, N){
        cin>>A[i];
        ll C=A[i];
        rep(j, 41){
            if(C%2==0)B[j]++;
          	C/=2;
        }
    }
  	rep(i, 41){
      	if(B[i]>N/2){
			B[i]=1;
        }
      	else{
          	B[i]=0;
        }
    }
  	
  	ll tot=0;
  	for(ll i=40; i>=0; i--){
      	ll num=1ll<<i;
		if(B[i]&&tot+num>K){
          	B[i]=0;
        }
      	else{
          	tot+=B[i]*num;
        }
    }
  	ll Ans=0;
  	rep(i, N){
      	Ans+=tot^A[i];
    }
    cout<<Ans<<endl;
}
     