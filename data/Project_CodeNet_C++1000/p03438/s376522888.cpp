#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N;
  cin>>N;
  vector<int> A(N),B(N);
  for(int &i:A)cin>>i;
  for(int &i:B)cin>>i;
  int cnta=0,cntb=0,suma=0,sumb=0;
  for(int i=0;i<N;i++)
    suma+=A[i],sumb+=B[i],cnta+=(max(B[i]-A[i],0LL)+1)/2,cntb+=max(A[i]-B[i],0LL);
  if(suma>sumb || sumb-suma<max(cnta,cntb))puts("No");
  else puts("Yes");
}