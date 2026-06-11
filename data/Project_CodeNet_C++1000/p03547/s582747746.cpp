#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep2(i, a, b) for(int i = (a); i < (b); i++)
typedef long long ll;

int main() {
   char x, y;
   cin >> x >> y;

   if (x < y) {
       cout << "<" << endl;
   } else if (x == y) {
       cout << "=" << endl;
   } else {
       cout << ">" << endl;
   }
}