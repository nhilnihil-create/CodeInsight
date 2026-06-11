#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep2(i, a, b) for(int i = (a); i < (b); i++)
typedef long long ll;

int main() {
   int k;
   cin >> k;

   int ans = (k % 2 == 0) ? pow(k/2, 2) : (k/2) * (k/2 + 1);

   cout << ans << endl;
}