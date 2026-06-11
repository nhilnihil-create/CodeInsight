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

//よくあるmodくん
const ll MOD = 1000000007; // = 10^9 + 7

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

void DO(int c, int x, vector<int> &t, vector<vector<int>> xy) {
  int XS = xy.size();
  if (t.at(x) != -1) {
    return;
  }
  t.at(x) = c;
  for (int i = 0; i < XS; i++) {
    if (xy.at(i).at(0) > x) {
      break;
    }
    if (xy.at(i).at(0) == x) {
      DO(c, xy.at(i).at(1), t, xy);
    }
    if (xy.at(i).at(1) == x) {
      DO(c, xy.at(i).at(0), t, xy);
    }
    
  }
}

int main() {
  int N, H, W;
  cin >> N >> H >> W;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    int A, B;
    cin >> A >> B;
    if (A >= H && B >= W) {
      ans++;
    }
  }
  cout << ans << endl;
}
    
    
  
  
  