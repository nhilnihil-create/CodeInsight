
 //#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <time.h>
 
using namespace std;
 
typedef long long ll;
const ll nmax = 1e9 + 7;
const ll MOD = 998244353;
const double PI = 2 * asin(1);

ll count(ll A, ll B, ll C, ll D){
  ll M = max(max(A, B), max(C, D));
  ll m = min(min(A, B), min(C, D));
  return M - m;
}

int main(){
  int N; cin >> N;
  vector <ll> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  vector <ll> sum(N);
  sum[0] = A[0];
  for (int i = 1; i < N; i++) sum[i] = sum[i - 1] + A[i];

  ll ans = 1e16;
  int L = 0, R = 2;
  for (int border = 1; border < N - 2; border++){
    ll L1 = sum[L], L2 = sum[border] - sum[L];
    for (int i = L + 1; i < border; i++){
      if (abs((L1 + A[i]) - (L2 - A[i])) < abs(L1 - L2)){
        L1 += A[i]; L2 -= A[i]; L++;
      }else{
        break;
      }
    }

    if (R == border) R++;
    ll R1 = sum[R] - sum[border], R2 = sum[N - 1] - sum[R];

    for (int i = R + 1; i < N - 1; i++){
      if (abs((R1 + A[i]) - (R2 - A[i])) < abs(R1 - R2)){
        R1 += A[i]; R2 -= A[i]; R++;
      }else{
        break;
      }
    }
    ll now = count(L1, L2, R1, R2);
    ans = min(ans, now);
  }

  cout << ans << endl;  

  return 0;
}