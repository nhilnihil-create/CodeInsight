#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<char> data(4);
  for (int i = 0; i < 4; i++) {
    cin >> data.at(i);
  }

  // 答えを保持する変数
  int answer = 0 ;

  for (int i = 0; i < 4; i++) {

    if (data.at(i) == '2' ) {
      answer++;
    }

  }

  cout << answer << endl;
}
