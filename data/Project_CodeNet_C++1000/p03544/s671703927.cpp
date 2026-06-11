#include <bits/stdc++.h>
using namespace std;
int main() {

  int N;
  cin >> N;

  vector<int64_t> ans(N+1);
  
  for(int i=0; i<N+1; i++){
    if(i == 0){
      ans.at(i)=2;
    }
    
    if(i == 1){
      ans.at(i)=1;
    }
    
    if( i >= 2){
    ans.at(i)=ans.at(i-1) + ans.at(i-2);
    }
  
  }
  
  cout << ans.at(N) << endl;
}
