#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
  ll N;
  cin >> N;
  
  ll ans = 0;
  for (ll i = 1; i <= N / 2; i++){
    ll kouho = (N - i) / i;
    if (kouho > i){
      if ((N - i) % i == 0){
        ans += kouho;
      }
    }
    else{
      break;
    }
  }

  cout << ans << endl;
}