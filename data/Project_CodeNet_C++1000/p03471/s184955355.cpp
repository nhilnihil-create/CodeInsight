#include <bits/stdc++.h>
using namespace std;

/*
fukuzawaがa枚, higuchiがb枚, noguchiがc枚あるとして、制約よりn = a + b + c
for分を三重にせずともcはc = n - a - bで求まるので、二重で済む。
これにより最悪計算量が8,000,000,000から4,000,000に減る。
1秒間で処理できるforループの回数は10^8 = 100,000,000回程度。三重では2秒間に収まらない。
*/

int main() {
  int n, y;
  cin >> n >> y;
  
  int fukuzawa = -1, higuchi = -1, noguchi = -1;
  for (int i = 0; i <= n; i++) {  // n = a
    for (int j = 0; (i + j) <= n; j++) {  // n = a + b
      int k = n - i - j;  // n = a + b + c
      int total = (10000 * i) + (5000 * j) + (1000 * k);
      if (total == y) {
        fukuzawa = i;
        higuchi = j;
        noguchi = k;
      }
    }
  }
  
  cout << fukuzawa << " " << higuchi << " " << noguchi << endl;
}