#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long int li;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef pair<ll, ll>P;
#define PI 3.14159265359
#define MOD 998244353
const int MAX = 510000;

int main() {
  ll N;cin>>N;
  vector<int>C(N);
  vector<int>S(N);
  vector<int>F(N);
  rep(i,N-1){cin>>C[i+1]>>S[i+1]>>F[1+i];}
  for(int i=1;i<N;i++){
  	ll time=S[i]+C[i];
  	for(int j=i+1;j<N;j++){
    	if(S[j]>=time){time=S[j]+C[j];}
      	else{
        	ll x=time/F[j];
        	ll y=time%F[j];
          	if(y==0){time=(F[j]*x)+C[j];}
          	else{time=(F[j]*(x+1))+C[j];}
        }
    }
    cout<<time<<endl;
  }
  cout<<0;
}