#include <iostream>
#include <stdio.h>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
 
typedef long long ll;

#define rep(i,n) for(ll i = 0; i < n; i++)

using namespace std;
 
const ll INF = ll(1e18)+1;
const double PI=3.14159265358979323846;

int main(){
  int N;
  string S;
  cin >> N >> S;

  int A[300010] = {};
  for(int i = 1; i<=N; i++){
    if(S[i-1] == 'E') A[i] = A[i-1] + 1;
    else A[i] = A[i-1];
  }
  int ans = 1e+9;
  for(int i = 1; i<=N; i++){
    ans = min(ans, A[N]-A[i] + i-1-A[i-1] );
  }
  cout << ans << endl;
}
