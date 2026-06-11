#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main()
{
  int n;
  cin >> n;
  
  map<int, int> mp;
  rep(i,n)
  {
    int a;
    cin >> a;
    mp[a]++;
  }
  
  int res = 0;
  for(auto x : mp)
  {
    if(x.second < x.first) res += x.second;
    else res += x.second - x.first;
  }
  cout << res << endl;
  
}