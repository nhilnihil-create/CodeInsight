#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<n;i++)
int main() {
  int n;
  string s;
  cin>>n>>s;
  int ans=0;
  rep(i,n-1){
    vector<bool>a(26);
    rep(j,i+1){
      a[s[j]-'a']=true;
    }
    int answer=0;
    for(int k=i+1;k<n;k++){
      if(a[s[k]-'a']) {
        answer++;
        a[s[k]-'a']=false;
      }
    }
    ans=max(ans,answer);
  }
  cout<<ans<<endl;
}
