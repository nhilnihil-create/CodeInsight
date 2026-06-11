#include "bits/stdc++.h"
using namespace std;

int main()
{
  int n;
  string ans="Yes";
  cin>>n;
  vector<string> s(n);
  for(int i=0;i<n;i++)
  {
    cin>>s.at(i);
    for(int j=0;j<i;j++)
    {
      if(s.at(i)==s.at(j))
      {
        ans="No";
        break;
      }
    }
  }
  for(int i=0;i<n-1;i++)
  {
    if(s.at(i).at(s.at(i).size()-1)!=s.at(i+1).at(0))
    {
      ans="No";
      break;
    }
  }
  cout<<ans<<endl;
}