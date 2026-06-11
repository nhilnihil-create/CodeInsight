#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

template<typename T>
T gcd(T a, T b) {
  if(a < b) swap(a,b);
    
  if(b == 0) return a;
  return gcd(b, a % b);
}

// 約数列挙 O(√n)
vector<ll> divisor(ll n){
  vector<ll> res;
  for(ll i = 1; i * i <= n; i++){
    if(n % i == 0){
      res.push_back(i);
      if(i != n / i) res.push_back(n / i);
    }
  }
  return res;
}

int main(){
  cout << setprecision(10);
  ll A,B,K; cin >> A >> B >> K;

  ll C = gcd(A, B);
  auto D = divisor(C);
  sort(D.rbegin(), D.rend());
  cout << D[K-1] << endl;
}
