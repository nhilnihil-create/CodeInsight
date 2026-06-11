#include <bits/stdc++.h>
using namespace std;

int main() {
  // ここにプログラムを追記
  int N,A;
  cin >> N >> A;
  int ans;
  int yen = N%500;
  if(yen<=A){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}
