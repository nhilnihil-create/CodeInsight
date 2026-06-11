#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  string S;
  cin >> S;
  cout << S[0] - '1' + (S.size() - 1) * 9 +
              all_of(begin(S) + 1, end(S), [](int x) { return x == '9'; })
       << endl;
}
