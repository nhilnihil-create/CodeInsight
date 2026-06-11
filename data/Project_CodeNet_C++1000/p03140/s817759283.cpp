#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  string A, B, C;
  cin >> N >> A >> B >> C;
  int count=0;
  for(int i=0; i<N; i++){
    if((A[i]!=B[i])&&(A[i]!=C[i])&&(B[i]!=C[i])){
      count+=2;
    }
    else if((A[i]!=B[i]) || (A[i]!=C[i]) || (B[i]!=C[i])){
      count++;
    }
  }
  cout << count << endl;
  return 0;
}