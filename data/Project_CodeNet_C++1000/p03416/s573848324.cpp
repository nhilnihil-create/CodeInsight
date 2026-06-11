#include <bits/stdc++.h>
using namespace std;

int main(){
  int A, B, i, cnt = 0;
  string s;
  cin >> A >> B;

  for ( i = A; i < B + 1; i++)
  {
    s = to_string(i);
    if (s[0] == s[4] && s[1] == s[3])
    {
      cnt ++;
    }
  }

  cout << cnt << endl;
}