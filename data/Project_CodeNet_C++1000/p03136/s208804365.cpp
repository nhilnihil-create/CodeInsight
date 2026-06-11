#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using i64 = int64_t;
using ll = long long;
int main() {
  int N;
  cin >> N;
  int m = 0;
  int sum = 0;
  rep(i,N){
    int A;
    cin >> A;
    m = max(m,A);
    sum += A;
  }
  if(2*m < sum){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
  return 0;
}