#include <bits/stdc++.h>
using namespace std;
int main(){
  string S,T;
  cin>>S>>T;
  int N=S.size();
  vector<vector<int>> A(26),B(26);
  for(int i=0;i<N;i++){
    A[S[i]-'a'].push_back(i);
    B[T[i]-'a'].push_back(i);
  }
  sort(A.begin(),A.end());
  sort(B.begin(),B.end());
  if(A==B)puts("Yes");
  else puts("No");
}