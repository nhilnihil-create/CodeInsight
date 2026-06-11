#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int min, max;
  cin >> min >> max;
 
  // ここにプログラムを追記
  int s1, s2, s3, s4, s5;
  int ans;
  int count = 0;
  for (int i=min; i<=max; i++) {
    s1 = i/10000;
    s2 = i/1000 - s1*10;
    s3 = i/100 - s2*10 - s1*100;
    s4 = i/10 - s3*10 - s2*100 - s1*1000;
    s5 = i - s4*10 - s3*100 - s2*1000 - s1*10000;
    ans = s5*10000 + s4*1000 + s3*100 + s2*10 + s1;
    if (ans - i == 0) {
      count++;
    }
  }
  cout << count << endl;
}