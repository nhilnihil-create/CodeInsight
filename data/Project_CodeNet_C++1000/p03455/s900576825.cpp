#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;

int main() {
  string Ans;
  int A; cin >>A;
  int B; cin >>B;
  Ans=(A*B)%2==0 ? "Even" : "Odd";
  cout << Ans << '\n';
  return 0;
}
