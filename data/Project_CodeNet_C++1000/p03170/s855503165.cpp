#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,k;
  cin>>n>>k;
  vector<int> v(n);
  int mn=INT_MAX;
  for(int i=0;i<n;i++)
  {
    cin>>v[i];
    if(v[i]<mn)
        mn=v[i];
  }
  vector<bool> v1(k+1);
  for(int i=0;i<mn;i++)
    v1[i]=false;
  for(int i=mn;i<=k;i++)
  {
    v1[i]=false;
    for(int j=0;j<n;j++)
    {
       if(i>=v[j]&&!v1[i-v[j]])
       {
         v1[i]=true;
         break;
       }
    }
  }
  if(v1[k])
    cout<<"First"<<endl;
  else
    cout<<"Second"<<endl;
  return 0;
}

