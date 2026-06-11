#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
  string s;
  cin>>s;
  if(s[0]!='A')
    {cout<<"WA"; return 0;}
    ll cnt=0;
  for(int i=1;i<s.size();i++)
  {
      if(s[i]=='C'&&i>1&&i<s.size()-1)
        cnt++;
     else if('A'<=s[i]&&s[i]<='Z')
        {cout<<"WA"; return 0;}
  }
  if(cnt==1)
    cout<<"AC"<<endl;
  else
    cout<<"WA";
}
    
    
