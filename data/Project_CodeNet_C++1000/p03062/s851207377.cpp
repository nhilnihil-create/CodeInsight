#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int MOD = 1000000007;
const int INF = 1e12;
using Graph = vector<vector<int>>;

signed main(){
  int N;
  cin >> N;

  bool zero = 0;
  int M = 0;
  vector<int> A(N);
  int t = 0;
  for( int i = 0; i < N; i++ ){
    cin >> A[i];
    if( A[i] < 0 ) M++;
    else if( A[i] == 0 ) zero = 1;
    A[i] = abs(A[i]);
    t += A[i];
  }

  sort(A.begin(), A.end());
  if( M%2 == 0 || zero == 1 ){
    cout << t << endl;
  }else{
    cout << t-2*A[0] << endl;
  }



}
