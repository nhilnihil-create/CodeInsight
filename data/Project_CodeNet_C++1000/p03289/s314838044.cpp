#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

//ライブラリ始まり

//定数

//円周率
const double PI = 3.1415926535897932384;

//天井
const int INF = 1000000000; // = 10^9
const ll LINF = 1000000000000000; // = 10^15

//ABC文字列
const string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZABC";
const string abc = "abcdefghijklmnopqrstuvwxyzabc";

//関数

//ctoi
int ctoi(char c){
  if (c == '0') {
    return 0;
  }
  if (c == '1') {
    return 1;
  } 
  if (c == '2') {
    return 2;
  } 
  if (c == '3') {
    return 3;
  }
  if (c == '4') {
    return 4;
  } 
  if (c == '5') {
    return 5;
  } 
  if (c == '6') {
    return 6;
  }
  if (c == '7') {
    return 7;
  } 
  if (c == '8') {
    return 8;
  } 
  if (c == '9') {
    return 9;
  }
  return -1;  
}

//素数判定
bool PN(int x) {
  if (x <= 1) {
    return false;
  }
  if (x == 2) {
    return true;
  }
  for (int i = 2; i < sqrt(x) + 1; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

//ライブラリ終わり
 
int main() {
  string S;
  cin >> S;
  if (S.at(0) != 'A') {
    cout << "WA" << endl;
  }
  else {
    int SS = S.size();
    int C = 0;
    int B = 0;
    for (int i = 2; i < SS - 1; i++) {
      if (S.at(i) == 'C') {
        C++;
      }
      for (int j = 0; j < 26; j++) {
        if (S.at(i) == ABC.at(j)) {
          B++;
        }
      }
    }
    for (int j = 0; j < 26; j++) {
      if (S.at(1) == ABC.at(j)) {
        B++;
      }
      if (S.at(SS - 1) == ABC.at(j)) {
        B++;
      }
    }
    if (C != 1) {
      cout << "WA" << endl;
    }
    else if (B != C) {
      cout << "WA" << endl;
    }
    else {
      cout << "AC" << endl;
    }
  }
}