#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
int main()
{
  int n;cin>>n;
  vector<int> b(n);
  int i;
  rep(i,n)cin>>b[i];
  bool ok=true;
  int len=n;
  int now=len-1;
  vector<int> take(n);
  while(len>0&&now>=0)
  {
    if(b[now]==now+1)
    {
      take[len-1]=b[now];
      for(i=now;i<len-1;i++)b[i]=b[i+1];
      len--;
      now=len-1;
    }
    else now--;
  }
  if(len>0)cout<<-1<<endl;
  else rep(i,n)cout<<take[i]<<endl;
}
