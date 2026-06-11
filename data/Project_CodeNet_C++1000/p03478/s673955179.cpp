#include <bits/stdc++.h>
using namespace std;

int SumDigit(int i) {
  int res=0;
  while (i>0) {
    res+=i%10;
    i/=10;
  }
  return res;
}
int Calc(int i, int a, int b) {
  int x=SumDigit(i);
  if (a <= x && x <=b) return i;
  return 0;
}
int main() {
  int N, A, B;
  cin >> N >> A >> B;
  int ans=0;
  for (int i=1; i<=N; i++) {
    ans+=Calc(i, A, B);
  }
  cout << ans << endl;
}
