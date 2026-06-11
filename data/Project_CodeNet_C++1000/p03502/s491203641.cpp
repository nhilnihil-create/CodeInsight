#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,N1,S=0;
  cin >> N;
  N1 = N;
  do
    S+=(N1%10);
  while(N1/=10);
  if(N%S)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
  // ここにプログラムを追記
}
