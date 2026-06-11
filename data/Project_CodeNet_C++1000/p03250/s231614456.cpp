#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  vector<int> n(3);

  rep(i,3){
    cin >> n.at(i);
  }

  int ans = 0;
  sort(n.begin(), n.end());

  // rep(i,3){
  //   cout << n[i];
  // }

  cout << n.at(2) * 10 + n.at(1) + n.at(0);
}
