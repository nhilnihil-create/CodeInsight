#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N,T,A;
  cin >> N >> T >> A;
  
  vector<int> H(N);
  for(int i=0; i<N; i++){
    cin >> H.at(i);
  }
  
  int tem = 0;
  int c = 100000000;
  int ans = 0;
  for(int i=0; i<N; i++){
    tem = (T * 1000 - H.at(i) * 6) - A * 1000;
    if(tem < 0){
      tem = -tem;
    }
    
    if(c > tem){
      c = tem;
      ans = i+1;
    }
    
    
  }
  
  cout << ans << endl;
  
}
