#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
using namespace std;


int main() {
  string s, t;
  cin >> s >> t;
  int n = s.size();
  while(n--){
    s = s[s.size()-1] + s;
    s.pop_back();
    if(s == t){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}