#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int ans = min(a+c, min(a+d, min(b+c, b+d)));
  cout << ans << endl;
}