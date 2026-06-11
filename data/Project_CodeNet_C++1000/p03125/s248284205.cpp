#include <bits/stdc++.h>
#define rep(i, e, n) for (int i = e; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,ll>;
const ll inf=1000000000007;
const int mod=1000000007;


int main() {
  int a,b; cin >> a >> b;
  if(b%a==0) cout << a+b << endl;
  else cout << b-a << endl;

  return 0;

}
