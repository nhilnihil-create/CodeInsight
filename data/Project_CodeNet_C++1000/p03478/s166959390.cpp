#include <bits/stdc++.h>
using namespace std;

int zyuu(int i) {
  int z=0;
  while (i>0) {
    z+=i%10;
    i/=10;
  }
  return z;
}

int main() {
  int N, A, B, S=0;
  cin >> N >> A >> B;
  for (int i=1; i<=N; i++) {
    if (zyuu(i)>=A && zyuu(i)<=B) {
      S+=i;
    }
  }
  cout << S << endl;
}
