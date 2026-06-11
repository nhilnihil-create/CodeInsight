#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep2(i, a, b) for(int i = (a); i < (b); i++)
typedef long long ll;

int main() {
   string s[2];
   rep(i, 2) {
       cin >> s[i];
   }

   if (s[0][0] == s[1][2] && s[0][1] == s[1][1] && s[0][2] == s[1][0]) {
       cout << "YES" << endl;
   } else {
       cout << "NO" << endl;
   }
}