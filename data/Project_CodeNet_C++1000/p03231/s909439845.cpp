# include <iostream>
# include <algorithm>
# include <cmath>
using namespace std;

# define ll long long

ll gcd(ll a, ll b){
  return b==0 ? a : gcd(b, a%b);
}

ll lcm(ll a, ll b){
  return a/gcd(a,b) * b;
}

int main(){

  int N, M;
  cin >> N >> M;
  string S, T;
  cin >> S >> T;

  int g = gcd(N,M);
  int n = N/g;
  int m = M/g;

  bool flag = true;
  for(int k=0; k<g; k++){
    if(S[n*k] != T[m*k]){
      flag = false;
      break;
    }
  }

  if(flag) cout << lcm(N, M) << endl;
  else cout << -1 << endl;
  return 0;
}