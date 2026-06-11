#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,m;
  map<int,int>cm;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    int t;
    cin>>t;
    cm[t]++;
  }
  
  set<int>ds;
  map<int,int>dm;
  cin>>m;
  for(int i=0;i<m;i++)
  {
    int t;
    cin>>t;
    dm[t]++;
    ds.insert(t);
  }
  for(auto t:ds )
  {
    if(dm[t]>cm[t])
    {
      cout<<"NO"<<endl;
      return 0;
    }
  }
  cout<<"YES"<<endl;
  return 0;
}