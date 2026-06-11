#include <bits/stdc++.h>
using namespace std;
int main(){
  
  int N;
  string A;
  string B;
  string C;
  
  cin >> N;
  cin >> A;
  cin >> B;
  cin >> C;
  
  int num = 0;
 
  for(int i = 0;i < N;++i){
    num = num + 2;
    if(A[i] == B[i] && B[i] == C[i]){
      num = num - 2;
    }
    else if(A[i] == B[i] || B[i] == C[i] || A[i] == C[i]){
      num = num - 1;
    }
  }
  
  cout << num << endl;
}
