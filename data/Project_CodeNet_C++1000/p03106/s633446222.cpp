#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, K;
  cin >> A >> B >> K;

  int i = 0;
  int num = 100;
  do {
    if(A%num== 0&& B%num==0) i++;
    num--;
  } while(i!=K);

  cout << num+1 << endl;
  return 0;
}