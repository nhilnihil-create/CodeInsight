#include <bits/stdc++.h>
using namespace std;

int main()
{
 int cnt = 0;
  string s;
  cin>>s;
  int d = s.size();
  for(int i=0;i < d;i++)
  {
    if(s[i] == 'x')
      cnt++;
  }
  if (cnt>=8)
    cout<<"NO"<<endl;
    else
      cout<<"YES"<<endl;
  return 0;
}