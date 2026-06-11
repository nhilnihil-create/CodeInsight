#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
  int n;

  ll sum = 0;

  cin >> n;

  vector<int> a(n);
  rep(i, n) cin >> a.at(i);

  rep(i,n){
    while(a.at(i) %2 == 0){
      a.at(i) /= 2;
      sum++;
    }
  }
  cout << sum << endl;
}
