#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int A, B, K;
  cin >> A >> B >> K;

  for (int i = A; i <= B; i++){
    if (A <= i && i <= A + K - 1 || B - K + 1 <= i && i <= B){
      cout << i << endl;
    }
  }
}
