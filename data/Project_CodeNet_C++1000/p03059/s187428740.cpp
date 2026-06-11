#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

int main(){
  int a, b, t, s;
  cin >> a >> b >> t;
  s=(t+0.5)/a;
  printf("%d\n", s*b);

  return 0;
}