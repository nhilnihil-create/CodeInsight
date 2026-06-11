#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  
  int A[N];
  for(int i=0; i<N; i++){
    cin >> A[i];
  }
  
  int maximum =0;
  
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(i!=j && abs(A[i]-A[j]) > maximum){
        maximum=abs(A[i]-A[j]);
      }
    }
  }
  
  cout << maximum << endl;
    
}