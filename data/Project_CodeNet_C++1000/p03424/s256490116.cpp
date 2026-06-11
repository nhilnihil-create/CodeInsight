#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;

int main() {
  int N;
  cin >> N;

  set<string> arares;
  string arare;
  rep(i, N) {
    cin >> arare;
    arares.insert(arare);
  }

  switch (arares.size()) {
    case 3:
      cout << "Three" << endl;
      break;
    case 4:
      cout << "Four" << endl;
      break;
  }
}
