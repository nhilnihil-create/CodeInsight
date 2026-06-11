#include<bits/stdc++.h>

using namespace std;

int main(void)
{
  string s;
  vector<char>res;
  string sout;

  cin>>s;

  for(int i=0;i<3;i++)
  {
    res.push_back(s[i]);
  }

  sort(res.begin(),res.end());

  for(int i=0;i<3;i++)
  {
    sout+=res[i];
  }

  if(sout=="abc")
  {
    cout<<"Yes"<<endl;
  }
  else
  {
    cout<<"No"<<endl;
  }
  
}