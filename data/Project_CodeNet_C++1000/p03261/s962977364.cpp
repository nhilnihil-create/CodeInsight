#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<string>w(n);
  for(int i=0;i<n;i++) cin>>w[i];
  string ans="Yes";
  for(int i=0;i<n-1;i++){
    int x=w[i].size();
    if(w[i][x-1]!=w[i+1][0]) ans="No";
  }
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      if(w[i]==w[j]) ans="No";
    }
  }
  cout<<ans<<endl;
}
