#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  int A, B;
  cin >> A >> B;
  A--;
  B--;

  char a[100][100];

  for (int i = 0; i < 50; i++) {
    for (int j = 0; j < 100; j++) {
      a[i][j] = '#';
    }
  }
  for (int i = 50; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      a[i][j] = '.';
    }
  }

  for (int i = 1; i < 50; i+=2) {
    bool flag = false;
    for (int j = 1; j < 100; j+=2) {
      if (A == 0) {
        flag = true;
        break;
      }
      a[i][j] = '.';
      A--;
    }
    if (flag) {
      break;
    }
  }
  for (int i = 51; i < 100; i+=2) {
    bool flag = false;
    for (int j = 1; j < 100; j+=2) {
      if (B == 0) {
        flag = true;
        break;
      }
      a[i][j] = '#';
      B--;
    }
    if (flag) {
      break;
    }
  }
  cout << 100 << " " << 100 << endl;
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      cout << a[i][j];
    }
    cout << endl;
  }
  return 0;
}