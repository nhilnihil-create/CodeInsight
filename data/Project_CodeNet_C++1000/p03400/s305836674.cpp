#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int N, D, X;
  cin >> N >> D >> X;
  vector <int> A(N);
  rep(i,N) cin >> A[i];

  int cnt = 0;
  rep(i,N){
    int day = 1;
    while (day <= D){
      cnt ++;
      day += A[i];
    }
  }
  cout << X + cnt << endl;
}
