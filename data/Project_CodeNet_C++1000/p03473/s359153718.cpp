#include <bits/stdc++.h>
using namespace std;
 
int main() {
  
  //入力を受け取る
  int N = 0;
  cin >> N;
  
  //24時間で表記する
  N -= 24;
  
  cout << abs(N - 24);
}
