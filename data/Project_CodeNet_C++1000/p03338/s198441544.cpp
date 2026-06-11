#include <iostream>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  string s;
  int ans = 0;
  cin >> s;
  for(int i = 1; i < n; i++){
    int cnt = 0;
    for(char c = 'a'; c <= 'z'; c++){
      bool left = false;
      bool right = false;
      for(int j = 0; j < i; j++){
        if(s.at(j) == c) left = true;
      }
      for(int j = i; j < n; j++){
        if(s.at(j) == c) right = true;
      }
      if(left && right) cnt++;
    }
    ans = max(ans,cnt);
  }
  cout << ans << endl;
}
