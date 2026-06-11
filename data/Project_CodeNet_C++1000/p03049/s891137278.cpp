#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<string> s(n);
  for(int i=0;i<n;i++) cin>>s[i];
  
  int bb=0,aa=0,ab=0,ba=0,ans=0;
  for(int i=0;i<n;i++){
    if(s[i][0]=='B'&&s[i][s[i].size()-1]!='A') bb++;
    else if(s[i][0]!='B'&&s[i][s[i].size()-1]=='A') aa++;
    else if(s[i][0]=='B'&&s[i][s[i].size()-1]=='A') ba++;
  	for(int j=0;j<s[i].size();j++){
    	if(s[i][j]=='A'&&s[i][j+1]=='B') ab++;
    }
    ans+=ab;
    ab=0;
  }
  if(bb==0&&aa==0&&ba==0) ans=ans;
  else if(bb==0&&aa==0&&ba!=0) ans+=(ba-1);
  else ans+=min(bb+ba,aa+ba);
  cout<<ans<<endl;
  
}