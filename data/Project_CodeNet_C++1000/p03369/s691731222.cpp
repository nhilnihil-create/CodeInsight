#include<bits/stdc++.h>

using namespace std;

int main(void)
{
  string s;
  int count=0;
  
  cin>>s;
  for(int i=0;i<s.size();i++)
  {
    if(s[i] == 'o')
    {
      count++;
    }
  }
  cout<<700+100*count<<endl;
  return 0;
}
