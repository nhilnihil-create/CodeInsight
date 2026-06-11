#include <bits/stdc++.h>
using namespace std;

int main() {
 int n; cin >> n;
 string s; cin >> s;
 vector<bool> front(26,0),back(26,0);
 int  cnt=0,ans=0;

  for(int i=1;i<n-1;i++){
    for(int j=0;j<i;j++){
       int x=s[j]-'a';
       front[x]=1;
    }
    for(int k=i;k<n;k++){
       int y=s[k]-'a';
       back[y]=1;
    }
    for(int l=0;l<26;l++){
      if(front[l]==1 && back[l]==1)cnt++;
    }
    ans=max(cnt,ans);
    cnt=0;
    for(int l=0;l<26;l++){
      front[l]=0;back[l]=0;
    }
  }
  cout << ans << endl;
}