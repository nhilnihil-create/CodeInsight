#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep2(i, a, b) for(int i = (a); i < (b); i++)
typedef long long ll;

int main() {
   int a, b, c;
   cin >> a >> b >> c;

   if (b >= (c - a) && c >= a) {
       cout << "YES" << endl;
   } else {
       cout << "NO" << endl;
   }
}