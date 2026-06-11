#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;
typedef pair<int, int> P;

vector<vector<int>> f(string s)
{
  vector<vector<int>> ret(26, vector<int>(0));
  vector<char> m(26, 'X');
  
  int n = s.size();
  char p = 'a';
  rep(i, n)
  {
    int c = s[i] - 'a';
    if(m[c] == 'X')
    {
      m[c] = p;
      p++;
    }
    ret[m[c] - 'a'].emplace_back(i);
  }
  
  return ret;
  
}


int main()
{
  string s, t;
  cin >> t >> s;
  vector<vector<int>> a(26, vector<int>(0)), b(26, vector<int>(0));
  a = f(s);
  b = f(t);
  
  rep(i, 26)
  {
    if(a[i] != b[i])
    {
      cout << "No" << endl;
      return 0;
    }
    /*
    rep(j, a[i].size())
    {
      if(a[i][j] != b[i][j])
      {
        cout << "No" << endl;
        return 0;
      }
    }*/
  }
  
  cout << "Yes" << endl;
  
  return 0;
}