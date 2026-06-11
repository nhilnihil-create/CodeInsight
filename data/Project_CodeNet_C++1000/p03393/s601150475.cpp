#include <bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  cin>>s;
  vector<int>a(27);
  for(int i=0;i<s.length();i++)
  {
    a[s[i]-'a'+1]++;
  }
  if(s.length()!=26)
  {	
    cout<<s;
    for(int i=1;i<=26;i++)
    {
      if(!a[i])
      {
        char c='a'+i-1;
        cout<<c<<endl;
        break;
      }
    }
  }
  else 
  {
    int cur=s.length();
    int flag=0;
    while(cur>0)
    {
      a[s[cur-1]-'a'+1]=0;
      s[cur-1]='\0';
      cur--;
      if(cur==0)break;
      if(s[cur-1]=='z')continue;
      for(int i=s[cur-1]-'a'+2;i<=26;i++)
      {
        if(a[i]==0)
        {
          s[cur-1]='a'+i-1;
          for(int w=0;w<cur;w++)cout<<s[w];
          flag=1;
          break;
        }
      }
      if(flag)break;    
    }
    if(!flag)cout<<-1<<endl;
  }
  return 0;
}