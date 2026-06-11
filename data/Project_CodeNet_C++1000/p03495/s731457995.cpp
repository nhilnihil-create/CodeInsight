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
    
  sort(B.begin(),B.end(),greater<int>());
  int mi = 0;

  for(int i=0;i<K;i++){
    mi += B.at(i);
  }

  if(N-mi <= 0){
    cout << 0 << "\n";
  }else{
    cout << N-mi << "\n";
  }  
}
    
  