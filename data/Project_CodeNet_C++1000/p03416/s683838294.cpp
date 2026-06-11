#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int a, b, n, c;
  int ans = 0;
  cin >> a >> b;
  
  n = b - a + 1;

  rep(i,n){
    int c1,c2,c3,c4,c5 = 0;
    c = a;
    c1 = c / 10000;
    c2 = (c - c1*10000) / 1000;
    c3 = (c - c1*10000 - c2*1000) / 100;
    c4 = (c - c1*10000 - c2*1000 - c3*100) / 10;
    c5 = (c - c1*10000 - c2*1000 - c3*100 - c4*10);
    if(c1 == c5 && c2 == c4){
      ans++;
    }
	a++;
  }
  cout << ans << endl;
}
