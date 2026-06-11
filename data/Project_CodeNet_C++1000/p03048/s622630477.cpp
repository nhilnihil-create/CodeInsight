#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  int R, G, B, N;
  cin >> R >> G >> B >> N;

  int ret = 0;
  for (int i = 0; i <= N / R; ++i) {
    int rest = N - i * R;
    if (rest < 0)
      continue;
    for (int j = 0; j <= rest / G; ++j) {
      int rest2 =  rest - j * G;
      if (rest2 < 0)
        break;
      if (rest2 % B == 0)
        ++ret;
    }
  }

  cout << ret << endl;

  return 0;
}