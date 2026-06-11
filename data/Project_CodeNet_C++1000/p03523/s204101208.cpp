#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  cin>>s;
  if(s.size()>9||s.size()<5) {
    cout<<"NO";
    return 0;
  }
  string tmp;
  for(int i=0;i<s.size();i++){
    if(s[i]!='A'){
      tmp.push_back(s[i]);
    }
    if(i==s.size()-1);
    else if((s[i]=='K'||s[i]=='I'||s[i]=='A')&&s[i+1]=='A'){
      cout<<"NO";
      return 0;
    }
  }
  cout<<(tmp=="KIHBR"?"YES":"NO");
} 