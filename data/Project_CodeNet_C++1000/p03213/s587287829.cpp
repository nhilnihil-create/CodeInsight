#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N;
  cin>>N;
  vector<int> A(100,0);
  for(int i=2;i<=N;i++){
    int j=i;
    for(int k=2;k<=j/k;k++)
      for(;j%k==0;j/=k)
        A[k]++;
    if(j!=1)
      A[j]++;
  }
  vector<int> B(0);
  for(int i=0;i<50;i++)
    if(A[i])
      B.push_back(A[i]);
  int M=B.size(),ans=0;
  for(int i=0;i<M;i++){
    if(B[i]>=74)
      ans++;
    for(int j=0;j<M;j++){
      if(i==j)continue;
      if(B[i]>=24 && B[j]>=2)
        ans++;
      if(B[i]>=14 && B[j]>=4)
        ans++;
      if(i>=j)
        continue;
      for(int k=0;k<M;k++)
        if(i!=k && j!=k && B[i]>=4 && B[j]>=4 && B[k]>=2)
          ans++;
    }
  }
  cout<<ans<<endl;
}