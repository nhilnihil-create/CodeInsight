#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;cin>>s;
  if(s.length()==1){cout<<s[0]-'0';return 0;}
  int currsum=0;
  int n = s.length();
  for(int i=0;i<n;i++)currsum+=s[i]-'0';
  cout<<max(currsum,(n-1)*9+s[0]-'0'-1);
}