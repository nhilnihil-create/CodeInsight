#include<bits/stdc++.h>
using namespace std;
int main(){
  long long i, mn=1000000000000001, N, n;
  cin >> N;
  for(i=0;i<5;i++){
    cin>>n;
    mn=min(n, mn);
  }
  cout<<4+(N+mn-1)/mn<<endl;
  return 0;
}