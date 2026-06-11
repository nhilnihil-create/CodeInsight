#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
  int N; cin >> N;
  map<string, int> mp;
  string str; cin >> str;
  mp.emplace(str, 1);
  for(int i = 1; i < N; i++) {
    string input; cin >> input;
    if(str[int(str.size()) - 1] != input[0]) continue;
    str = input;
    mp.emplace(str, i + 1);
  }
  if(mp.size() == N) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}