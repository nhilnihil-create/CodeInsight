#include <iostream>
using namespace std;
string A = "AKIHABARA";
int I[]{8,6,4,0};
int main() {
  string S;
  cin >> S;
  bool flag{0};
  for (int i = 0, n = 1 << 4; i != n; ++i) {
    string B{A};
    int j = i, k{};
    while(j) {
      if (j&1) B.erase(I[k],1);
      ++k, j >>= 1;
    }
    if (S == B) {
      flag = 1;
      break;
    }
  }
  cout << (flag ? "YES" : "NO") << endl;
}
