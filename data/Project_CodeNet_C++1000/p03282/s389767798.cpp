#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  int64_t K;
  cin >> S >> K;
  
  int ans =1;
  int N = S.size();
  for(int i=0; i<N; i++){
    if(S.at(i)!='1' && i<K){
      ans = 0;
      cout << S.at(i) << endl;
      break;
    }
  }
  
  if(ans)cout << ans << endl;
}