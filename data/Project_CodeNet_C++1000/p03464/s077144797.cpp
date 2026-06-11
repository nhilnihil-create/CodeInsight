#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

int main(){
  ll K, tmp;
  cin >> K;
  vector<ll> A;
  for (ll i=0; i<K; i++){
    cin >> tmp;
    A.push_back(tmp);
  }
  ll l = 2;
  ll r = 2;
  ll l2, r2;
  ll f = 0;
  for (ll i=K-1; i>=0; i--){
    f = A[i];
    l2 = f * (ceil((double)l / (double)f));
    r2 = f * (floor((double)r / (double)f));
    if (l2 > r && r2 < l){
      l = -1;
      r = -1;
      break;
    }
    l = l2;
    r = r2 + f - 1;
    cerr << l << " " << r << endl;
  }
  
  if (l == -1){
    cout << -1 << endl;
  }
  else{
    cout << l << " " << r << endl;
  }
  return 0;
}
  
