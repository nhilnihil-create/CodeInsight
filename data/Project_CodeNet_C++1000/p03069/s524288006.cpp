#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin >> n;
  string s;cin >> s;
  vector<int> b(n+1),w(n+1);
  for(int i=0;i<n;i++){
    if(s[i]=='#'){
      b[i+1]++;
    }
    else{
      w[i]++;
    }
  }
  for(int i=0;i<n;i++){
    b[i+1]+=b[i];
  }
  for(int i=n-1;i>=0;i--){
    w[i]+=w[i+1];
  }
  int ans=1e6;
  for(int i=0;i<=n;i++){
    ans=min(ans,b[i]+w[i]);
  }
  cout << ans << endl;
}