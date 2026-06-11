#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;string s;cin>>n>>s;
  int ans=0;
  for(int i=1;i<n-1;i++){
    int cnt=0;
    vector<int> l(26),r(26);
    for(int j=0;j<i;j++)l[s[j]-'a']=1;
      for(int k=i;k<n;k++)r[s[k]-'a']=1;
        rep(i,26){
          if(l[i]==1&&r[i]==1)cnt++;
        }
    ans=max(ans,cnt);
  }
  cout<<ans<<endl;
}