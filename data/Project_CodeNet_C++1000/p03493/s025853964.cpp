#include <bits/stdc++.h>
using namespace std;

int main() {
  // ここにプログラムを追記
  int s123, s1, s2, s3;
  
  cin >> s123;
  s1 = s123/100;
  s2 = (s123-s1*100)/10;
  s3 = s123%10;
  cout << s1+s2+s3 << endl;
}