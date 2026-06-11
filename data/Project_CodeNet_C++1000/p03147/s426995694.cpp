/**
*    author:  yuya1234
*    created: 10.07.2020 10:22:07
**/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define FORV(i,v) for(auto i=v.begin(); i!=v.end();i++)

#define SORT(s) sort((s).begin(),(s).end())
#define SORTD(s) sort((s).rbegin(),(s).rend())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

#define SZ(x) ((int)(x).size())
#define MEMSET(v, h) memset((v), h, sizeof(v))
int solve(int l,int r,int* h){
  int nmin=INT_MAX-1;
  FOR(i,l,r)
  {
    nmin=min(nmin,h[i]);
  }

  FOR(i,l,r)
  {
    h[i]-=nmin;
  }
  return nmin;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int n;
  cin>>n;

  int h[n];
  REP(i,n)cin>>h[i];

  int ans=0;
  for(;;)
  {
    bool flg=true,flg0=false;
    int l=0,r=0;
    REP(i,n)
    {
      if(h[i]!=0)flg=false;

      if(!flg0 && h[i]>0)
      {
        l=i;
        r=i;
        flg0=true;
      }
      else if(flg0 && h[i]==0)
      {
        r=i-1;
        break;
      }
      else if(flg0 && h[i]>0)
      {
        r=i;
      }
    }
    if(flg)break;
    
    ans+=solve(l,r,h);
  }

  cout<<ans<<endl;

  return 0;
}