#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  string s, t;
  cin >> s >> t;
  vector<int> from(26, -1);
  vector<int> to(26, -1);
  rep(i, (int)s.size()) {
    int start = s[i] - 'a';
    int end = t[i] - 'a';
    
    if (to[end] != -1 && to[end] != start) {
      cout << "No" << endl;
      return 0;
    }
    if (from[start] != -1 && from[start] != end) {
      cout << "No" << endl;
      return 0;      
    }
    from[s[i] - 'a'] = t[i] - 'a';
    to[t[i] - 'a'] = s[i] - 'a';
  }
  cout << "Yes" << endl;
  return 0;
}