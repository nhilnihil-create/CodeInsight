#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int>A(N);
  for(int i=0; i<N; i++)cin >> A.at(i);
  
  int count = 0;
  bool X = true;
  while(X){
    for(int j=0; j<N; j++){
      if(A.at(j)%2==0)A.at(j)/=2;
      else{
        X = false;
        break;
      }
    }
    
    if(X)count ++;
  }
  
  cout << count << endl;
    
}