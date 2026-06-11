#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;string s;cin>>n>>s;
  int ans=0;
  for(int i=1;i<n-1;i++){
    vector<int> a(26),b(26);
    for(int j=0;j<i;j++)a[s[j]-'a']=1;
    for(int j=i;j<n;j++)b[s[j]-'a']=1;
    int cnt=0;
    rep(j,26){
      if(a[j]==1&&b[j]==1)cnt++;
    }
    ans=max(ans,cnt);
  }
  cout<<ans<<endl;
}