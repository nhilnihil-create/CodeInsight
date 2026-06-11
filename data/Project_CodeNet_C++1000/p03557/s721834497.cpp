#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N;
  cin>>N;
  vector<int> A(N),B(N),C(N);
  for(int &i:A)
    cin>>i;
  for(int &i:B)
    cin>>i;
  for(int &i:C)
    cin>>i;
  sort(A.begin(),A.end());
  sort(C.begin(),C.end());
  int ans=0;
  for(int i:B){
    ans+=(lower_bound(A.begin(),A.end(),i)-A.begin())*(N-(upper_bound(C.begin(),C.end(),i)-C.begin()));
  }
  cout<<ans<<endl;
}