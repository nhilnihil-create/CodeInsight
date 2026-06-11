#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<int> V(N),C(N);
  for(int &i:V)
    cin>>i;
  for(int &i:C)
    cin>>i;
  int j=0;
  for(int i=0;i<N;i++)
    if(V[i]>C[i])
      j+=V[i]-C[i];
  cout<<j<<endl;
}