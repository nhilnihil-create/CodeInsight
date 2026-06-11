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
  vector<int> a(n);
  vector<int> b(n);
  int i;
  rep(i,n) cin >> a[i] >> b[i];
  vector<pair<int,int>> sum(n);
  rep(i,n)
  {
    sum[i] = make_pair(a[i]+b[i],i);
  }
  sort(all(sum));
  reverse(all(sum));
  ll ans = 0;
  rep(i,n)
  {
    int ind = sum[i].second;
    if(i%2==0)
    {
      ans += a[ind];
    }
    else
    {
      ans -= b[ind];
    }
  }
  cout << ans << endl;
}