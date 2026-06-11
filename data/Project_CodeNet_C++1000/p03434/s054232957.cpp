#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N;
  cin>>N;
  vector<int> A(N);
  for(int &i:A)cin>>i;
  sort(A.rbegin(),A.rend());
  int a=0,b=0;
  for(int i=0;i<N;i++){
    if(i%2==0)a+=A[i];
    else b+=A[i];
  }
  cout<<a-b<<endl;
}