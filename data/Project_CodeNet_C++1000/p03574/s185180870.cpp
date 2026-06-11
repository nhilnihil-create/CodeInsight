#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, start, end) for (int i = (int)start; i < (int)(end); i++)

string operator*(string str, size_t n) {
  string result = "";
  rep(i, n){
  	result += str;
  }
  return result;
}


int main() {
  int h, w;
  int cnt;
  cin >> h >> w;
  vector<string> stage(h);
  rep(y, h) {
  	cin >> stage[y];
  }
  rep(y, h) {
  	rep(x, w) {
      if (stage[y][x] == '#') continue;
      cnt = 0;
      range(addx, -1, 2){
      	range(addy, -1, 2) {
          //cout << x + addx << y + addy << endl;
          if (0 <= x + addx && x + addx < w && 0 <= y + addy && y + addy < h) {
            if (stage[y + addy][x + addx] == '#') cnt += 1;
          }
        }
      }
      stage[y][x] = '0' + cnt;
    }
  }
  rep(y, h) {
  	cout << stage[y] << endl;
  }
}