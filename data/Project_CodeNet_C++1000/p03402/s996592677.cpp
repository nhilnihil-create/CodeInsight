#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;

char maze[101][101];

int main(){
  int white, black;
  cin >> white >> black;
  white--;
  black--;
  for (int i = 0; i < 50; i++) {
    for (int j = 0; j < 100; j++) {
      maze[i][j] = '.';
    }
  }
  for (int i = 50; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      maze[i][j] = '#';
    }
  }
  for (int i = 0; i < 50; i += 2) {
    for (int j = 0; j < 100; j += 2) {
      if (black > 0) {
        maze[i][j] = '#';
        black--;
      } else {
        break;
      }
    }
  }
  for (int i = 51; i < 100; i += 2) {
    for (int j = 0; j < 100; j += 2) {
      if (white > 0) {
        white--;
        maze[i][j] = '.';
      } else {
        break;
      }
    }
  }
  cout << "100 100" << endl;
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      cout << maze[i][j];
    }
    cout << endl;
  }
  return 0;
}
