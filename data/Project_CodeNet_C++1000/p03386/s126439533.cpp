#include <iostream>

using namespace std;
typedef long long ll;

int main(){
  ll A, B, K;
  cin >> A >> B >> K;
  for (ll i = 0; i < K && A + i <= B; i++){
    printf("%lld\n", A + i);
  }
  for (ll i = K - 1; i >= 0; i--){
    if (B - i > A + K - 1) printf("%lld\n", B - i);
  }
}
