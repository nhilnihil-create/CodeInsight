#include <bits/stdc++.h>
using namespace std;

int main() {
   string a, b, c;
   int ans;
   cin >> a;
   
   if (a == "111") { ans = 3; }
   if (a == "110") { ans = 2; }
   if (a == "101") { ans = 2; }
   if (a == "011") { ans = 2; }
   if (a == "100") { ans = 1; }
   if (a == "010") { ans = 1; }
   if (a == "001") { ans = 1; }
   if (a == "000") { ans = 0; }
   cout << ans << endl;
}