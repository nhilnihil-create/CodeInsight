#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  vector<int> vec(3);
  rep(i,3)cin>>vec[i];
  int k;cin>>k;
  sort(all(vec));
  reverse(all(vec));
  rep(i,k)vec[0]*=2;
  int cnt=0;
  rep(i,3)cnt+=vec[i];
  cout<<cnt<<endl;
}