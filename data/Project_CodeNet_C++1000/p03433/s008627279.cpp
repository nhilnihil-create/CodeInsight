#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
  int n, a;
  cin >> n >> a;
  int waru = n % 500;
  // cout << waru;

  if(waru<=a)
    cout << "Yes";
  else
  {
    cout << "No";
  }

}
