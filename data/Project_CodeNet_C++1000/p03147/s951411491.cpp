#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n; cin>>n;
  vector<int> h(n);
  for(int i=0; i<n; ++i) cin>>h[i];
  vector<int> f(n,0);
  int cnt=0,left=0;
  while(left<n){
    while(f[left]==h[left]) ++left;
    for(int i=left; f[i]<h[i]&&i<n; ++i) ++f[i];
    ++cnt;
  }
  cout<<cnt-1<<endl;
  return 0;
}