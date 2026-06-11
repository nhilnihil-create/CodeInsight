#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  int count = 0;
  for(int i = A; i < B + 1; i++){//AからBまで実行するコマン
    if((i - i % 10000) / 10000 == i % 10 && (i % 10000 - i % 1000) / 1000 == (i % 100 - i % 10)/ 10){
    count++;
    }
  }
  cout << count << endl;
}
