#include <bits/stdc++.h>
#include <string>
using namespace std;

int main() {
  string k;
  cin >> k;
  bool n9flag = true;
  int sento = k.at(0) - '0'; //数値変換
  int size = k.size() - 1;
  for (int i = 1; i < k.size(); i ++) {
  	// 全部９でないか確認
    int j = k.at(i) - '0';
    if (j != 9) {
    	n9flag = false;
      	break;
    }
  }
  if (n9flag) {
    int result = sento + size * 9;
  	cout << result << endl;
  } else {
  	int result = sento + size * 9 - 1;
  	cout << result << endl;
  }
}
