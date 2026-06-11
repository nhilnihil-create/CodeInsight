#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main()
{
  ll n; cin>>n;
  for(int i =0; i*4 <= n; i++) {
    for(int j =0; j*7 <= n; j++) {
      if(i*4 + j*7 == n) {
        cout << "Yes" << endl;
        return 0;
      };
    }
  }
  cout << "No" << endl;
  return 0;
}