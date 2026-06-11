#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll MOD=1000000007;

int main() {
  ll N,K;
  cin >> N >> K;
  if(K%2==1){
    cout << (N/K)*(N/K)*(N/K) << endl;
  }
  else{
    ll t=N/K;
    ll S=2*N/K;
    cout << t*t*t+(S-t)*(S-t)*(S-t) << endl;
  }
}