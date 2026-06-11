#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  vector<long> A(n);
  vector<long> B(n);
  long sum=0;
  for(int i=0;i<n;i++){
    cin >> A[i];
    sum-=A[i];
  }
  for(int i=0;i<n;i++){
    cin >> B[i];
    sum+=B[i];
  }
  
  long An=0,Bn=0;
  for(int i=0;i<n;i++){
    if(A[i]>B[i]){
      Bn+=A[i]-B[i];
    }
    else{ 
      An+=(B[i]-A[i]+1)/2;
    }
  }
  if(An > sum || Bn > sum){
    cout << "No";
  }
  else{
    cout << "Yes";
  }
}
