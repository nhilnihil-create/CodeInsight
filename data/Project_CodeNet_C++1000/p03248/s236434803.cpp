#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef pair<int,int> P;

int main()
{
  string s;
  cin >> s;
  
  if(s[0] == '0' || s.back() == '1')
  {
    cout << -1 << endl;
    return 0;
  }
  
  while(true)
  {
    if(s.back() == '0')
    {
      s.erase(s.end()-1);
    }
    else break;
  }
  
  int n = s.size();
  rep(i,n)
  {
    if(s[i] != s[n-1-i])
    {
      cout << -1 << endl;
      return 0;
    }
  }
  
  
  vector<P> edge;
  int left = 0;
  for(int i = 1; i < n; i++)
  {
    if(s[i] == '1')
    {
      for(int j = left; j < i; j++)
      {
        edge.push_back(P(j, i));
      }
      left = i;
    }
  }
  edge.push_back(P(left, n));
  
  //cout << (int)edge.size() << endl;
  for(auto x : edge) cout << x.first + 1 << " " << x.second + 1 << endl;
  
  
  return 0;
}