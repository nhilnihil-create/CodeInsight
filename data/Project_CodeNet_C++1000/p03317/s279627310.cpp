#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  int al;
  for(int i = 0; i < N; i++){
    cin >> A.at(i);
  }
  int ans;
  
  if((N-1)%(K-1)==0){
    ans = (N-1) / (K-1);
  }
   else{
    ans = ((N-1)/(K-1))+1;
  }
  
  cout << ans << endl;
 
    
}