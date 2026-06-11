#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

int main(){
  ll N,K;
  cin >> N >> K;
  ll ans = 0;
  if(K%2==0){
    ans += pow((N+K/2)/K,3);
    ans += pow(N/K,3);
  }else{
    ans += pow(N/K,3);
  }
  cout << ans << endl;
}
