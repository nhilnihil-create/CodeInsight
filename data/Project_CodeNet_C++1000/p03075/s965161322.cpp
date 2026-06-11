#include <bits/stdc++.h>
#define rep(i, e, n) for (int i = e; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const ll inf=1000000000007;

int main() {
  int a,b,c,d,e,k;
  cin >> a >> b >> c >> d >> e >>k;
  if((e-a)>k) cout << ":(" << endl;
  else cout << "Yay!" << endl;

  return 0;
}