#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int h, w;
  cin >> h >> w;
 
  // 入力文字を全連結
  string allIn;
  for (int i = 0; i < h; i++) {
    string in;
    cin >> in;
    allIn = allIn + in;
  } 
  //cout << allIn << endl;
  
  // マス数
  int S = allIn.size();
  
  // .のマスに対して周囲の#数を算出して置換
  for (int i = 0; i < S; i++) {
    //cout << i << "回目" << endl;
    char mat = allIn.at(i);
    if (mat != '.') {
      continue;
    }
    //#数
    int j = 0;
    // 周囲の文字変数
    char leftupper = 'X';
    char middleupper = 'X';
    char rightupper = 'X';
    char left = 'X';
    char right = 'X';
    char leftlower = 'X';
    char middlelower = 'X';
    char rightlower = 'X';
    // 文字取得
    //cout << "upper" << endl;
    if (i >= w) {
      middleupper = allIn.at(i-w);
      if (w != 1) {
        if ((i+1)%w != 1) { 
          leftupper = allIn.at(i-w-1);
        }
        if ((i+1)%w != 0) { 
          rightupper = allIn.at(i-w+1);
        }
      }
    }
    //cout << "middle" << endl;
    if (w != 1) {
      if ((i+1)%w != 1) { 
        left = allIn.at(i-1);
      }
      if ((i+1)%w != 0) { 
        right = allIn.at(i+1);
      }
    }
    //cout << "lower" << endl;
    if (i < w*(h-1)) {
      middlelower = allIn.at(i+w);
      if (w != 1) {
        if ((i+1)%w != 1) {
          leftlower = allIn.at(i+w-1);
        }
        if ((i+1)%w != 0) { 
          rightlower = allIn.at(i+w+1);
        }
      }
    }
    //cout << leftupper << middleupper << rightupper << left << right << leftlower << middlelower << rightlower << endl;
    if (leftupper == '#') {
      j += 1;
    }
    if (middleupper == '#') {
      j += 1;
    }
    if (rightupper == '#') {
      j += 1;
    }
    if (left == '#') {
      j += 1;
    }
    if (right == '#') {
      j += 1;
    }
    if (leftlower == '#') {
      j += 1;
    }
    if (middlelower == '#') {
      j += 1;
    }
    if (rightlower == '#') {
      j += 1;
    }
    char c = 'Z';
    if (j == 0) {
      c = '0';
    }
    if (j == 1) {
      c = '1';
    }
    if (j == 2) {
      c = '2';
    }
    if (j == 3) {
      c = '3';
    }
    if (j == 4) {
      c = '4';
    }
    if (j == 5) {
      c = '5';
    }
    if (j == 6) {
      c = '6';
    }
    if (j == 7) {
      c = '7';
    }
    if (j == 8) {
      c = '8';
    }
    // 代入
    allIn.at(i) = c;  
  }
  // 出力
  for (int i = 0; i < S; i++) {
    cout << allIn.at(i);
    if ((i+1)%w == 0) {
      cout << endl;
    }
  }
}