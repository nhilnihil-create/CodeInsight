#include "bits/stdc++.h"
using namespace std;

int main()
{
  int n,sum;
  sum=0;
  cin>>n;
  vector<int> l(n);
  for(int i=0;i<n;i++)
  {
    cin>>l.at(i);
    sum+=l.at(i);
  }
  sort(l.begin(),l.end());
  reverse(l.begin(),l.end());
  if(l.at(0)<sum-l.at(0))
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
}