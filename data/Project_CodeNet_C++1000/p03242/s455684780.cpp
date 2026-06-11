#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep2(i, a, b) for(int i = (a); i < (b); i++)
typedef long long ll;

int main() {
   string s;
   cin >> s;

   rep(i, 3) {
       s[i] = (s[i] == '1') ? '9' : '1';
   }

   cout << s << endl;
}