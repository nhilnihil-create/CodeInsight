#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  string s[n];
  int a = 0;
  int b = 0;
  int both = 0;
  for(int i = 0; i < n; i++) {
    string t;
    cin >> t;
    if(t[t.size()-1] == 'A' && t[0] == 'B') {
      both++;
    }else if(t[0] == 'B') {
      b++;
    }else if(t[t.size()-1] == 'A') {
      a++;
    }
    s[i] = t;
  }
  int ans = 0;
  for(int i = 0; i < n; i++) {
    string u = s[i];
    for(int j = 1; j < u.size(); j++) {
      if(u[j-1] == 'A' && u[j] == 'B') {
        ans++;
      }
    }
  }

  if(both == 0) {
    ans += min(a,b);
  }else if(a == 0 && b == 0) {
    ans += both-1;
  }else{
    ans += both + min(a,b);
  }
  cout << ans << endl;
  return 0;
}