#include<bits/stdc++.h>
using namespace std;

signed main(){

  string s;
  cin>>s;

  string t;
  for(int i=0;i<s.size();++i){
    if(s[i]=='A')t+='A';
    else if(i+1<s.size()&&s[i]=='B'&&s[i+1]=='C')t+='D',i++;
    else t+=s[i];
  }

  int64_t ans = 0;
  int64_t anum = 0;
  for(auto c:t){
    if(c=='A')anum++;
    else if(c=='D')ans+=anum;
    else anum=0;
  }
  cout<<(ans)<<endl;

}