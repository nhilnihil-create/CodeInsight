#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N;
  cin>>N;
  vector<int> A(N),B(N+1);
  B[0]=0;
  for(int i=0;i<N;i++){
    cin>>A[i];
    B[i+1]=B[i]+A[i];
  }
  map<int,int> C;
  for(int &i:B)
    C[i]++;
  int k=0;
  for(pair<int,int> p:C)
    k+=p.second*(p.second-1)/2;
  cout<<k<<endl;
}