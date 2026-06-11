#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < n; ++i)
#include <bits/stdc++.h>
using namespace std;
//~ using ll = long long;
//~ using P = pair<int, int>;

int main(){
  int a, b, k;
  int cnt=0;
  int i;
  cin >> a >> b >> k;
  if (a>b) i=b;
  else i=a;
  for (; i>0; i--) {
    if (a%i==0 && b%i==0)
      cnt++;
    if (cnt == k){
      cout << i << endl;
      break;
    }
  }
  return 0;
}
