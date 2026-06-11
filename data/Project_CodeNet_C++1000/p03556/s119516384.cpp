#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};

bool squareNumber(int n){
  for (int i = 1; i <= sqrt(n); i++){
    if (i * i == n) return true;
  }
  return false;
}
int main(void){
  int N;
  cin >> N;

  for (int i = N; i >= 1; i--){
    if (squareNumber(i)){
      cout << i << endl;
      return 0;
    }
  }
}
