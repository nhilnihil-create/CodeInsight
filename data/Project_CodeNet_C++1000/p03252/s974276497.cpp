#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;
typedef long long ll;

int main() {
  
  string s, t;
  cin >>  s >> t;
  
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  
  int n = s.size();
  vector<int> u(26);
  vector<int> v(26);
  int j = 0, k = 0;
  
  REP(i,n) {
    u[j]++;
    v[k]++;
    if(s[i] != s[i+1]) j++;
    if(t[i] != t[i+1]) k++;
  }
    
  sort(u.begin(), u.end());
  sort(v.begin(), v.end());
  
  bool ans = true;
  REP(i,26) {
    if (u[i] != v[i]) ans = false;
  }
  
  cout << (ans ? "Yes" : "No") << endl;
    
    
}