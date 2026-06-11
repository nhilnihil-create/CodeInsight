#include <iostream>
#include <vector>
using namespace std;
int n;
vector<string> s;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> n;
  s.resize(n);
  for(int i = 0; i < n; ++i) {
    cin >> s[i];
    s[i] = s[i] + s[i];
  }
  for(int i = 0; i < n; ++i) s.push_back(s[i]);

  int ans = 0;
  for(int i = 0; i < n; ++i) {
    bool ok = true;
    for(int j = 0; j < n; ++j) {
      for(int k = j+1; k < n; ++k) {
        if(s[i+j][k] != s[i+k][j]) {
          ok = false;
          break;
        }
      }
      if(!ok) break;
    }
    if(ok) ++ans;
  }
  cout << ans * n << endl;
  return 0;
}