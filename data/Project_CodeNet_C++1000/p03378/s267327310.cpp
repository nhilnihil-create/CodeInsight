#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int N, M, X;
  cin >> N >> M >> X;
  vector <int> A(N);
  rep(i,M) cin >> A[i];


  int left = 0;
  for (int i = 0; i < M; i++){
    if (A[i] < X) left ++;
  }

  int right = 0;
  for (int i = 0; i < M; i++){
    if (A[i] > X) right ++;
  }

  cout << min(left, right) << endl;
}
