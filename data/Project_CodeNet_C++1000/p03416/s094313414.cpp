#include <bits/stdc++.h>
using namespace std;
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int a, b, ans=0;
  string s;
  cin >> a >> b;

  rep2(i, a, b+1)
  {
    if(i%10 == i/10000%10 &&
       i/10%10 == i/1000%10
      )
    {
      ans++;
    }
  }

  cout << ans << endl;

}
