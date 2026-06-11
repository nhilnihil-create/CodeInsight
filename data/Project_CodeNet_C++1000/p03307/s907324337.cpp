#include<bits/stdc++.h>
using ll=long long;
using namespace std;
int main(){
  int N;
  cin>>N;
  int tmp=N*2;
  int ans=tmp/__gcd(N,2);
  cout<<ans<<endl;
  return 0;
}