#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int N,D,X;
  cin>>N>>D>>X;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  vector<int> a(101,0);
  for(int i=0;i<N;i++){
    for(int j=1;j<=D;j+=A[i]){
      a[j]++;
    }
  }
  int ans=0;
  for(int i=1;i<=D;i++){
    ans+=a[i];
  }
  cout<<ans+X<<endl;
}