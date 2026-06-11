#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
  ll d, n;
  cin >> d >> n;

  ll hundred = 1;

  rep(i, d) hundred *= 100;
  if(n<=99){
    cout << hundred * n;
  }
  else
  {
    cout << hundred * 101;
  }


}
