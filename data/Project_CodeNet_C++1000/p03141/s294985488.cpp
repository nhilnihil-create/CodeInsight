#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N,ans=0;
  cin>>N;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    int a,b;
    cin>>a>>b;
    A[i]=a+b;
    ans-=b;
  }
  sort(A.begin(),A.end());
  reverse(A.begin(),A.end());
  for(int i=0;i<N;i+=2)
    ans+=A[i];
  cout<<ans<<endl;
}