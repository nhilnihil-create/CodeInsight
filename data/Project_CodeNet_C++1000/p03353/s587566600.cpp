#include<bits/stdc++.h>
using namespace std;
int main()
{
 string s;int k;
  cin>>s>>k;
  set<string> v;
  for(int i=1;i<=k;i++)
  {
    for(int j=0;j+i-1<s.length();j++)
      v.insert(s.substr(j,i));
  }
  vector<string> vv;
  for(auto i:v) vv.push_back(i);
  cout<<vv[k-1];
 
  
  return 0;
}
