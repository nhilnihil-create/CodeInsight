#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
int main()
{
  int m,k;cin>>m>>k;
  int i;
  if(m==1)
  {
    if(k==0)cout<<"0 0 1 1"<<endl;
    else cout<<-1<<endl;
  }
  else if(k>=(1<<m))
  {
    cout<<-1<<endl;
  }
  else
  {
    rep(i,(1<<m)-1)
    {
      if(i!=0)cout<<' ';
      if(i<k)cout<<i;
      else cout<<i+1;
    }
    cout<<' '<<k;
    for(i=(1<<m)-2;i>=0;i--)
    {
      cout<<' ';
      if(i>=k)cout<<i+1;
      else cout<<i;
    }
    cout<<' '<<k<<endl;
  }
}