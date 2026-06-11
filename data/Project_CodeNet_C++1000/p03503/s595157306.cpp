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
  int N;cin>>N;
  int F[N][10];
  rep(i,N){
   	rep(j,10){
    	cin>>F[i][j];
    }
   }
  ll P[N][11];
  rep(i,N){
   	rep(j,11){
    	cin>>P[i][j];
    }
   }
  ll mgain=-1000000000;
   for (int tmp = 1; tmp < (1 << 10); tmp++) {
    bitset<10> s(tmp);
    int count[N]; 
    rep(i,N){count[i]=0;} 
    rep(i,N){
    	rep(j,10){
        	if(s.test(j)&&F[i][j]==1){count[i]++;}
        }
    }
    ll gain=0;
    rep(i,N){
    	gain+=P[i][count[i]];
    }
    mgain=max(mgain,gain); 
  }
  cout<<mgain; 
}