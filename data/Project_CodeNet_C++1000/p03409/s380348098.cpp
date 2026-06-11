#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define SX(x) (x).begin(), (x).end()
typedef pair<int, int> P;

int main()
{
  int n;	cin >> n;
  vector<P> a(n), b(n);
  rep(i,n) cin >> a[i].first >> a[i].second;
  rep(i,n) cin >> b[i].first >> b[i].second;
  sort(SX(a));
  sort(SX(b));
  
  int ans=0;
  rep(i,n) {
    int res=-1, tmp =-1;
    rep(j, a.size())
    {
      if (a[j].first < b[i].first && a[j].second < b[i].second)
      {
        if (a[j].second > res)
        {
          tmp = j;
          res = a[j].second;
        }
      }
    }
    if (res != -1)
    {
      a.erase(a.begin() + tmp);
      ans++;
    }
  }
  cout << ans << endl;
}