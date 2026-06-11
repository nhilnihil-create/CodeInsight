#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using i64 = int64_t;
using ll = long long;
int main() {
  int s;
  cin >> s;
  int ans;
  vector<int> v(1000001);
  v.at(s) ++;
  for(int i = 2;i <= 1000000;i++){
    int next;
    if(s % 2 == 0){
      next = s/2;
    }
    else{
      next = s*3 + 1;
    }
    if(v.at(next) == 1){
      cout << i << endl;
      return 0;
    }
    else{
      v.at(next) ++;
      s = next;
    }
  }
  cout << 1000000 << endl;
}