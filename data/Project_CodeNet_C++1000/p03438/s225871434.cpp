#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N;
  cin>>N;
  vector<int> A(N),B(N);
  int a=0,b=0;
  for(int &i:A){
    cin>>i;
    a+=i;
  }
  for(int &i:B){
    cin>>i;
    b+=i;
  }
  int cnt1=0,cnt2=0;
  for(int i=0;i<N;i++){
    if(A[i]<B[i])
      cnt2+=(B[i]-A[i]+1)/2;
    else if(A[i]>B[i])
      cnt1+=A[i]-B[i];
  }
  if(cnt1>b-a || cnt2>b-a)
    puts("No");
  else
    puts("Yes");
}