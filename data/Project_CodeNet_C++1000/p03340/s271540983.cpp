#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
int main()
{
  int n;
  cin >> n;
  int i,j;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  vector<bitset<20>> bs(n);
  rep(i,n) bs[i] = bitset<20>(a[i]);
  vector<vector<int>> bcount(n+1,vector<int>(20,0));
  rep(i,n)
  {
    rep(j,20)
    {
      bcount[i+1][j] = bcount[i][j] + bs[i][j];
    }
  }
  int left=0;
  int right=1;
  ll ans=0;
  while(right<=n)
  {
    bool ok=true;
    rep(j,20)
    {
      if(bcount[right][j]-bcount[left][j]>1)
      {
        ok=false;
      }
    }
    if(ok)
    {
      ans+=(right-left);
      right++;
    }
    else
    {
      left++;
      if(left>=right)right=left;
    }
  }
  cout<<ans<<endl;
}
