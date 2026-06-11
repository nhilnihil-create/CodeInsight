#include <iostream>
#include <set>

using namespace std;

const string YES = "Yes";
const string NO = "No";

int main() {
  int N;
  cin >> N;
  set<string> s;
  string W;
  char lastc{'\0'};
  bool pred{true};
  for (int i = 0; i < N; ++i) {
    cin >> W;
    if(!s.insert(W).second || (lastc && W.front() != lastc)) {
      pred = false;
      break;
    }
    lastc = W.back();
  }

  cout << (pred ? YES : NO) << endl;
  return 0;
}
