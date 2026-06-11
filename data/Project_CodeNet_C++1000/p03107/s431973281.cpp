#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{   
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int i;
  string str;
  cin>>str;
  int n=str.length();
  stack<char>s;
  i=0;
  int count=0;
  while(i<n)
  {
    if(s.size()==0)
      s.push(str[i]);
    else
    {
      if(str[i]=='0' && s.top()=='1' )
      {
        count+=2;
        s.pop();
      }
      else if(str[i]=='1' && s.top()=='0' )
      {
        count+=2;
        s.pop();
      }
      else
        s.push(str[i]);
    }
    i++;
  }
  cout<<count;

    return 0;
}