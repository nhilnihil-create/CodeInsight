#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<vector<int>> A(N-1,vector<int>(3));
  for(vector<int> &i:A)
    for(int &j:i)
      cin>>j;
  for(int i=0;i<N;i++){
    int t=0;
    for(int j=i;j<N-1;j++)
      t=(max(t,A[j][1])+A[j][2]-1)/A[j][2]*A[j][2]+A[j][0];
    cout<<t<<endl;
  }
}