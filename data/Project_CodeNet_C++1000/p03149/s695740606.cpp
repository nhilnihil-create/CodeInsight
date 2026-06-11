#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  vector<int> ans(10);
  rep(i,4){
    int n;cin>>n;
    ans[n]++;
  }
    if(ans[1]==1&&ans[7]==1&&ans[9]==1&&ans[4]==1)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}