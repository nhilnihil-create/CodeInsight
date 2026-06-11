#include <bits/stdc++.h>
// #include<atcoder/all>
using namespace std;
// using namespace atcoder;

int main() {
    int N, a, ans;
    ans = 9999999999;
    cin >> N;
    for(int i = 0;i<N ; i++) {
      cin >> a;
      int tmpAns = 0;
      while(a%2==0){
        tmpAns++;
        a = a/2;
      }
      ans = min(ans, tmpAns);
    }
  
  cout << ans << endl; 
  return 0;
}
