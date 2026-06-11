#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
const int INF = 100100100;
using namespace std;

int main()
{
  int A, B;
  int res=0;
  cin >> A >> B;

  res = A*B - A - B + 1;

  cout << res << endl;
}