#include <bits/stdc++.h>
using namespace std;

long long N;

long long dfs(string s) {
  if(stoll(s) > N) return 0;

  long long ret = 0;

  bool three = false, five = false, seven = false;
  for(char sub: s) {
    if(sub == '3') three = true;
    if(sub == '5') five = true;
    if(sub == '7') seven = true;

    if(three && five && seven) {
      ret++;
      break;
    }
  }

  for(string sub: {"3", "5", "7"}) {
    ret += dfs(s+sub);
  }

  return ret;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  cout << dfs("0") << endl;

  return 0;
}