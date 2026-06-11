#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  string S;
  cin >> S;
  int a{};
  for (int i = 0, n = S.size(); i != n; ++i ) {
    a += (i%2 == (S[i]-'0'));
  }
  cout << min(a,(int)S.size()-a) << endl;
}
