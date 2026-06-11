#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  string S;
  cin>>N>>S;
  int ma=0;
  for(int i=1;i<N-1;i++){
    vector<int> A(26),B(26);
    int j=0;
    for(;j<=i;j++)
      A[S[j]-'a']++;
    for(;j<N;j++)
      B[S[j]-'a']++;
    int k=0;
    for(int j=0;j<26;j++)
      if(A[j]>0 && B[j]>0)
        k++;
    ma=max(ma,k);
  }
  cout<<ma<<endl;
}