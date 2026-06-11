#include<bits/stdc++.h>
#define int long long
using namespace std;
int a(vector<int> &A,int &N,int l,int r){
  if(l>=r)
    return 0;
  int mn=100;
  for(int i=l;i<r;i++)
    mn=min(mn,A[i]);
  vector<int> B={-1};
  for(int i=l;i<r;i++){
    A[i]-=mn;
    if(A[i]==0)
      B.push_back(i);
  }
  B.push_back(r);
  int ans=0;
  for(int i=1;i<B.size();i++)
    ans+=a(A,N,B[i-1]+1,B[i]);
  return ans+mn;
}
signed main(){
  int N;
  cin>>N;
  vector<int> A(N);
  for(int &i:A)
    cin>>i;
  cout<<a(A,N,0,N)<<endl;
}