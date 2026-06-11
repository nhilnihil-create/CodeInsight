#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define int ll
string padd6(string s)
{
  if (s=="0")
    while(1);
	while (s.length() != 6)
      s = "0" + s;
  return s;
}
signed main()
{
 int n,m;
  cin >> n >> m;
  vector<pair<int,int>> v;
  vector<pair<int,int>> vv;
  for (int i = 0;i < m;i++)
  {
   int p,y;
    cin >> p >> y;
    v.push_back(make_pair(p,y));
    vv.push_back(make_pair(p,y));
  }
  sort(vv.begin(),vv.end());
  
  map<int, map<int, int>> mp;
  int num = 1;
  int prev = vv[0].first;
  for (int i= 0;i < m;i++)
  {
    if (prev != vv[i].first)
      num = 1;
    mp[vv[i].first][vv[i].second] = num;
    prev = vv[i].first;
	num++;
  }
  for (int i = 0;i < m; i++)
  {
    cout << padd6(to_string(v[i].first)) +  padd6(to_string(mp[v[i].first][v[i].second])) << endl;
  }
}
