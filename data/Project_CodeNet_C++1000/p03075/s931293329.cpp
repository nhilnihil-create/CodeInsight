#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int a[5], k;
  rep(i,5) cin >> a[i];
  cin >> k;

  if (a[4] - a[0] > k) cout << ":(" << endl;
  else cout << "Yay!" << endl;
}
