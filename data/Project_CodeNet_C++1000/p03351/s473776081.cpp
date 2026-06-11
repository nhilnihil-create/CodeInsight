#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  if(abs(a-c) <= d){
    cout << "Yes";
    return 0;
  }

  if(abs(a-b) <= d && abs(b-c) <= d){
    cout << "Yes";
  }
  else
  {
    cout << "No";
  }

}
