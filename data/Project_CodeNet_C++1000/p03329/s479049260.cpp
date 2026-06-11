#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void chmax(int& a, int b) {
  if (a == -1) a = b;
  if (a > b) a = b;
}
int main () {
  int nin[10];
  int six[10];
  nin[0] = 0;
  nin[1] = 9;
  six[0] = 0;
  six[1] = 6;
  for (int i = 2; i < 8; i ++) {
    nin[i] = nin[i - 1] * 9;
  }
  for (int i = 2; i < 10; i ++) {
    six[i] = six[i - 1] * 6;
  }
  int num_with[1000000];
  ll I_ma = 1000000;
  for (int i = 0; i < 1000000; i ++) num_with[i] = -1;
  ll with[18];
  for (int i = 0; i < 6; i ++) {
    with[i] = nin[i + 1];
  }
  for (int i = 6; i < 13; i ++) {
    with[i] = six[i - 5];
  }
  //for (int i = 0; i < 13; i ++) cout << with[i] << endl;
  num_with[0] = 0;
  for (int i = 0; i < 1000000; i ++) {
    if (num_with[i] != -1) {
      for (int j = 0; j < 13; j ++) {
        if (i + with[j] < I_ma) {
          chmax(num_with[i + with[j]], num_with[i] + 1);
        }
      }
    }
  }
  int N;
  cin >> N;
  int count = 0;
  while (num_with[N] == -1) {
    N --;
    count ++;
  }
  cout << num_with[N] + count << endl;
}