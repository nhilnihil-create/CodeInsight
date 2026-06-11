#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>

using namespace std;

const int nmax = 1e9 + 7;
const long long INF = 1e18;
const double PI = 2 * asin(1);
typedef long long ll;


int main(){
  int N, K; cin >> N >> K;
  vector <ll> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  vector <ll> all;
  for (int i = 0; i < N; i++){
    ll sum = 0;
    for (int j = i; j < N; j++){
      sum += A[j];
      all.push_back(sum);
    }
  }
  sort(all.begin(), all.end(), greater<ll>());

  ll num = all[0]; int cnt = 0;
  while (num > 0){
    num = num / 2;
    cnt++;
  }

  ll ans = 0;
  vector <ll> now = all;
  for (int i = cnt - 1; i >= 0; i--){
    ll L = pow(2, i);
    vector <ll> next;
    for (int j = 0; j < now.size(); j++){
      if (now[j] >= L){
        now[j] -= L;
        next.push_back(now[j]);
      }
    }
    
    if (next.size() >= K){
      now = next; ans += L;
    }
  }
  cout << ans << endl;


  return 0;
}