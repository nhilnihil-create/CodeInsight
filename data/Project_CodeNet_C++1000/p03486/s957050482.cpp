#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  string s,t;
  cin >> s >> t;

  sort(s.begin(),s.end());
  sort(t.rbegin(),t.rend());

  vector<string> u = {t,s};
  sort(u.begin(),u.end());
  if(u[0] == s && t != s) cout << "Yes" << endl;
  else cout << "No" << endl;
}
