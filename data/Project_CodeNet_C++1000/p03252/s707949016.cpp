#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  string s, t;
  cin >> s >> t;
  vector<int> a(26), b(26);
  for(int i=0; i<s.size(); i++) a[s[i]-'a']++;
  for(int j=0; j<t.size(); j++) b[t[j]-'a']++;
  sort(rng(a));
  sort(rng(b));
  cout << (a==b? "Yes": "No") << endl;
  return 0;
}