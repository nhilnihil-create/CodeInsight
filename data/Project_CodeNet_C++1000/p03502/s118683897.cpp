#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int digitSum(int n) {
  int res = 0;
  while(n > 0) {
    res += n%10;
    n /= 10;
  }
  return res;
}

int main(void){
  int N;
  cin >> N;

  if (N % digitSum(N) == 0) cout << "Yes" << endl;
  else cout << "No" << endl;
}
