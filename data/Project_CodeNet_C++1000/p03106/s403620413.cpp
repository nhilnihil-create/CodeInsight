#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int A, B, K;
  cin >> A >> B >> K;

  int x = max(A, B);
  int cnt = 0;
  for (int i = x; i > 0; i--){
    if (A % i == 0 && B % i == 0) cnt ++;
    else continue;
    if (cnt == K){
      cout << i << endl;
      return 0;
    }
  }
}
