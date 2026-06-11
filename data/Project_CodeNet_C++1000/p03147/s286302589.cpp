#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n; cin>>n;
  vector<int> h(n);
  for(int i=0; i<n; ++i) cin>>h[i];
  int cnt=0,left=0;
  while(left<n){
    while(h[left]==0) ++left;
    for(int i=left; h[i]&&i<n; ++i) --h[i];
    ++cnt;
  }
  cout<<cnt-1<<endl;
  return 0;
}