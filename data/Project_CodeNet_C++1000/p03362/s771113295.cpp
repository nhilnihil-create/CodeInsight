#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts

int main()
{
  int n;cin>>n;
  vector<bool> ptable(56000,true);
  ptable[0]=false;
  ptable[1]=false;
  int i,j;
  for(i=2;i<ptable.size();i++)
  {
    for(j=2*i;j<ptable.size();j+=i)ptable[j]=false;
  }
  int ans=0;
  i=2;
  while(ans<n)
  {
    if(ptable[i]&&(i%10==1))
    {
      if(ans!=0)cout<<' ';
      cout<<i;
      ans++;
    }
    i++;
  }
  cout<<endl;
}
