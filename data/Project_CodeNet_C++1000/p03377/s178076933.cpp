#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using i64 = int64_t;
using ll = long long;
int main() {
  int A,B,X;
  cin >> A >> B >> X;
  if(X >= A && X <= A+B){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
  return 0;
}