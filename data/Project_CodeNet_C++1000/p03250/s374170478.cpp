#include <bits/stdc++.h>
using namespace std;
typedef int64_t i64;

int main()
{
  int A,B,C;
  cin >> A >> B >> C;

  int ans = A + B + C + max(A,max(B,C)) * 9;
  
  cout << ans << endl;

}