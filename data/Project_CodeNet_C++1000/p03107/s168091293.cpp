#include <iostream>
#include <stack>

using namespace std;

int main() {
  char c;
  stack<char> S;
  int ans{};
  while(cin >> c) {
    if (S.empty() || S.top() == c) S.push(c);
    else {
      ans += 2;
      S.pop();
    }
  }
  cout << ans << endl;
}
