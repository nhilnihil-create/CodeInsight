#include <bits/stdc++.h>
using namespace std;
int main() {
int64_t X,Y;
cin >> X >> Y;
int64_t i = X,ans = 0;
while (i <= Y) {
  ans++;
  i *= 2;
}
cout << ans << endl;


return 0;
}