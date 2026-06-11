#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  string s;
  int k;
  cin >> s >> k;
  set<string> st;
  int n = s.size();
  rep(i, n) {
    string tmp = "";
    for(int j = i; j < min(i+5, n); j++) {
      tmp += s[j];
      st.insert(tmp);
    }
  }
  int cnt = 1;
  for(auto it = st.begin(); it != st.end(); it++) {
    if (cnt == k) {
      cout << *it << endl;
      return 0;
    }
    cnt++;
    
  }

  return 0;
}