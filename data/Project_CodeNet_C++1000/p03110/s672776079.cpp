#include "bits/stdc++.h"
using namespace std;

int main()
{
  int n;
  cin>>n;
  double ans=0;
  vector<pair<double,string>> a(n);
  for(int i=0;i<n;i++)
  {
    cin>>a.at(i).first>>a.at(i).second;
    if(a.at(i).second=="JPY")
      ans+=a.at(i).first;
    else
      ans+=a.at(i).first*380000;
  }
  cout<<ans<<endl;
}