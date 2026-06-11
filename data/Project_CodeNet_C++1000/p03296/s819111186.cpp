#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  
  for(int i=0;i<N;i++){
    if(A[i]==A[i+1]){
      A[i+1]=-1;
    }
  }
  
  int count=0;
  
  for(int i=0;i<N;i++){
    if(A[i]==-1){
      count++;
    }
  }
  
  cout << count << endl;
}
