#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

ll N,K;

int main(){
  cin >> N >> K;
  ll count = 0;
  for(ll b = K+1;b<=N;b++){
    ll s = N / b;
    ll a = N % b;
    count += s * (b-K);
    if(K != 0) count += max((ll)0,a-K+1);
    else count += a;
  }
  cout << count << endl;
  return 0;
}
