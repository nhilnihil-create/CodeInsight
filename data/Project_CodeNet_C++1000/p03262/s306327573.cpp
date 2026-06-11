#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

template<typename T>
T gcd(T a, T b) {
  if(a < b) swap(a,b);
    
  if(b == 0) return a;
  return gcd(b, a % b);
}

int main(){
  cout << setprecision(10);
  ll N,X; cin >> N >> X;

  ll ans;
  for(int i = 0; i < N; i++){
    ll tmp; cin >> tmp;
    tmp = abs(tmp - X);
    if(i == 0){
      ans = tmp;
    } else { 
      ans = gcd(ans, tmp);
    }
  }
  cout << ans << endl;
  
}
