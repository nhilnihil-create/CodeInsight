#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K;
  cin >> N >> K;
  
  int cnt = 0;
  vector<int> A(N);
  vector<int> B(200000,0);
  for(int i=0;i<N;i++){
    cin >> A.at(i);
    B.at(A.at(i)) ++;
    if(B.at(A.at(i)) == 1){
      cnt ++;
    }
  }
  if(cnt <= K){
    cout << 0 << "\n";
    return 0;
  }
    
  sort(B.begin(),B.end());
  int i_non0 = 0;
  for(int i=0;i<200000;i++){
    if(B.at(i)!=0){
      i_non0 = i;
      break;
    }
  }

  int ans = 0;
  
  for(int i=i_non0;i<i_non0+(cnt-K);i++){
    ans +=B.at(i);
  }
  cout << ans << "\n";
  
}
    
  