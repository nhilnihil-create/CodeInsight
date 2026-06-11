#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll N;
  cin>>N;
  vector<ll> A(N),B(N);
  for(int i=0;i<N;i++){
    cin>>A[i];
    B[i]=A[i]-i;
  }
  sort(B.begin(), B.end());
  ll b=B[N/2];
  ll tmp=0;
  for(int i=0;i<N;i++){
    tmp+=abs(-b+B[i]);
  }
  cout<<tmp<<endl;
}