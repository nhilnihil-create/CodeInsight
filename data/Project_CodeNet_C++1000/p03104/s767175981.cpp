#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

ll f(ll X){
  if(X<0){
    return 0;
  }

  ll ret = 0;
  ll Y = X / 4;
  Y *= 4;
  for(ll i = Y; i <= X; i++){
    ret ^= i;
  }

  return ret;
}

int main(){
  cout << setprecision(10);
  ll A,B; cin >> A >> B;
  cout << ( f(B) ^ f(A-1)) << endl;
}
