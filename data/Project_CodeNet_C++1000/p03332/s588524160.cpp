#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
using namespace std;

vector<ll> fac{1};
vector<ll> ifac{1};
vector<ll> inv{1};

ll F(ll N, ll a, ll p){
 
  if(a%2 == 0){
    
    if(a == 0)return 1;
 
    else return (F(N, a/2, p)*F(N, a/2, p))%p;
    
  }
 
  else return N*F(N, a - 1, p)%p;
 
}

ll Com(ll n, ll k, ll p){

  return (((fac[n]*ifac[k])%p)*ifac[n - k])%p;

}

int main(){
ll N, A, B, K, p = 998244353, Ans = 0;cin >> N >> A >> B >> K;

ll f = 1;
  
if(K == 0){cout << 1;exit(0);}

rep(i, 1, N + 1){

  f *= i;f %= p;

  fac.push_back(f);

}

rep(i, 1, N + 1){

  inv.push_back(F(i, p - 2, p));

}

f = 1;

rep(i, 1, N + 1){

  f *= inv[i];f %= p;
  ifac.push_back(f);

}

/*for(auto v : fac )cout << v << " ";
cout << endl;
for(auto v : inv )cout << v << " ";
cout << endl;
for(auto v : ifac )cout << v << " ";
cout << endl;
*/

  
rep(i, 0, N + 1){

  if((K - A*i)%B != 0 )continue;

  ll j = (K - A*i)/B;
  
  if(j > N || j < 0)continue;

  Ans += Com(N, i, p)*Com(N, j, p);Ans %= p;

}
cout << Ans;

}