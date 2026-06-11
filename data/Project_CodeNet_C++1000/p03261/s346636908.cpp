#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  vector<string> vec(n);
  rep(i,n)cin>>vec[i];
  rep(i,n-1)for(int j=i+1;j<n;j++){
    if(vec[i]==vec[j]){
      cout<<"No"<<endl;
      return 0;
    }
  }
  rep(i,n-1){
    if(vec[i][vec[i].size()-1]!=vec[i+1][0]){
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
}