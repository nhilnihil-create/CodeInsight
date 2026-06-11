#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int A;
  cin >> A;
  int Y, M;
  Y = A / 100;
  M = A % 100;
  int YM, MY;
  YM = MY = 0;
  if(1 <= M && M <= 12) {
    YM++;
  }
  if(1 <= Y && Y <= 12) {
    MY++;
  }
  if(YM == 1 && MY == 0) {
    cout << "YYMM" << endl;
  }
  else if(MY == 1 && YM == 0) {
    cout << "MMYY" << endl;
  }
  else if(MY == 0 && YM == 0) {
    cout << "NA" << endl;
  }
  else {
    cout << "AMBIGUOUS" << endl;
  }
}