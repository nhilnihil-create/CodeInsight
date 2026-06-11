#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using i64 = int64_t;
using ll = long long;
int main() {
  int N,M,X;
  cin >> N >> M >> X;
  vector<int> A(100);
  int sum = 0;
  rep(i,M){
    int a;
    cin >> a;
    A.at(a) = 1;
    if(a <= X){
      sum ++;
    }
  }
  int rest = M - sum;
  cout << min(sum,rest) << endl;
  return 0;
}