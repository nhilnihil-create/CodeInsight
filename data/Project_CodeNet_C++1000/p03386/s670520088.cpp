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

  if (B - A + 1 >= 2 * K){
    for (int i = 0; i < K; i++) cout << A + i << endl;
    for (int i = 0; i < K; i++) cout << B - K + 1 + i << endl;
  }else{
    for (int i = A; i <= B; i++) cout << i << endl;
  }
}
