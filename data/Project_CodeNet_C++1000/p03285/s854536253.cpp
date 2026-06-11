#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
  int n;
  cin >> n;

  rep(i,n){
    rep(j,n){
      if(4*(i)+7*(j) == n){
        cout << "Yes";
        return 0;
      }
    }
  }

  cout << "No";
}
