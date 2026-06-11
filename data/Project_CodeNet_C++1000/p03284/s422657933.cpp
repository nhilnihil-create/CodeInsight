#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep2(i, a, b) for(int i = (a); i < (b); i++)
typedef long long ll;

int main() {
   int n, k;
   cin >> n >> k;

   int ans = (n % k == 0) ? 0 : 1;

   cout << ans << endl;
}