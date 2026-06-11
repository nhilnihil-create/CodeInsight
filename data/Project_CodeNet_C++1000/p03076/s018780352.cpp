#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, D, E;
  cin >> A >> B >> C >> D >> E;
  
  int a, b, c, d, e, saisyo, ans;
  a=(A-1)%10+1;
  b=(B-1)%10+1;
  c=(C-1)%10+1;
  d=(D-1)%10+1;
  e=(E-1)%10+1;
  saisyo = min(a, min(b, min(c, min(d,e))));
  ans=A+B+C+D+E-a-b-c-d-e+40+saisyo;
  
  cout << ans << endl;
}