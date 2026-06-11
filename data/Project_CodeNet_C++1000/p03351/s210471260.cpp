#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; ++i)
using ll = long long;
const ll MOD = 1000000007;//998244353;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int a, b, c, d; cin >> a >> b >> c >> d;
   if (abs(a-c)<=d || (abs(a-b)<=d && abs(b-c)<=d))
      cout << "Yes" << endl;
   else
      cout << "No" << endl;

}