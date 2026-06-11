#include <bits/stdc++.h>
using namespace std;
int main(){
  int N; cin>>N;
  vector<long long>A(N,0);
  long long ans=0;
  for(int i=0;i<N;i++){
    int a;cin>>a;
    A[i]=(i==0? 0:A[i-1])+a;
    if(A[i]==0)ans++;
  }
  sort(A.begin(),A.end());
  int count=1;
  for(int i=1;i<N;i++){
    if(A[i]==A[i-1]){ans+=count;count++;}
    else count=1;
  }
  cout<<ans<<endl;
}