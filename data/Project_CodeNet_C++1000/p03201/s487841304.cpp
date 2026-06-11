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
  int N; cin >> N;
  vector <ll> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  sort(A.begin(), A.end(), greater<ll>());

  map <ll, ll> count;
  for (int i = 0; i < N; i++){
    count[A[i]]++;
  }
  

  ll ans = 0;
  for (int i = 0; i < N - 1; i++){
    if (count[A[i]] > 0){
      ll num = A[i], cnt = 0;
      while (num > 0){
        cnt++; num /= 2;
      }
      ll next = pow(2, cnt) - A[i];

      if (count[next] > 0 && A[i] != next){
        ans++; count[next]--;
      }else if(count[next] > 1 && A[i] == next){
        ans++; count[A[i]]--;
      }
      count[A[i]]--;
    }
  }
  cout << ans << endl;


  return 0;
}