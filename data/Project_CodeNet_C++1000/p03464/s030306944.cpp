#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<50;
const ll MOD = 1e9+7;
const double EPS = 1e-9;


int main(int argc, const char * argv[]) {
  int K; cin >> K;
  vector<ll> A(K);
  for(int i=0; i<K; i++) cin >> A[i];
  
  reverse(A.begin(), A.end());
  ll aMax = 2, aMin = 2;
  for(int i=0; i<K; i++){
    ll lower = (aMin + A[i] - 1) / A[i] * A[i];
    ll upper = (aMax - aMax%A[i]);
    if(lower > aMax || upper < aMin){
      cout << -1 << endl;
      return 0;
    }
    aMax = upper+A[i]-1;
    aMin = lower;
  }
  cout << aMin << " " << aMax << endl;
  return 0;
}