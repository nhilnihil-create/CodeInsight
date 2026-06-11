#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1000000007;
int N,A[200100],B[200100];
signed main(){
  cin>>N;
  for(int i=0;i<200000;i++)A[i]=-1;
  B[0]=1;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    B[i+1]=(B[i]+(A[a-1]!=i && A[a-1]!=-1?B[A[a-1]]:0))%mod;
    A[a-1]=i+1;
  }
  cout<<B[N]<<endl;
}