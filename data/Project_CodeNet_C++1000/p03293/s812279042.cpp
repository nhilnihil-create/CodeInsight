#include<bits/stdc++.h>
using namespace std;

#define int long long int 

int32_t main()
{
  string s,t;
  cin>>s>>t;
  t+=t;
  if(t.find(s)!=-1)
  cout<<"Yes"<<endl;
  else
  cout<<"No"<<endl;
}