#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W, a;
  cin >> H >> W;
  string S[H + 2], T[H];
  for (int i = 0; i < W + 2; i++) S[0] += '.' ;
  for (int i = 0; i < W + 2; i++) S[H + 1] += '.' ;
  for (int i = 1; i < H + 1; i++) {
  	cin >> S[i];
    S[i] = '.' + S[i] + '.';
  }

  for (int i = 1; i < H + 1; i++) {
    for (int j = 1; j < W + 1; j++) {
	  if (S[i].at(j) == '#') {
		T[i - 1] += '#';
      } else {
        a = 0;
        if (S[i - 1].at(j - 1) == '#') a++;
        if (S[i - 1].at(j) == '#') a++;
        if (S[i - 1].at(j + 1) == '#') a++;
        if (S[i].at(j - 1) == '#') a++;
        if (S[i].at(j + 1) == '#') a++;
        if (S[i + 1].at(j - 1) == '#') a++;
        if (S[i + 1].at(j) == '#') a++;
        if (S[i + 1].at(j + 1) == '#') a++;
        T[i - 1] += to_string(a);
        }
    }
    a = 0;
  }
  
  for (int i = 0; i < H; i++) cout << T[i] << endl;

  return 0;
}

