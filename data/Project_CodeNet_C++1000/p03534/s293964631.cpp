#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define debug(x) cerr << #x << ": " << x << endl;

int main() {
   string s;
   cin >> s;
   vector<int> v(3);
   v[0] = count(s.begin(), s.end(), 'a');
   v[1] = count(s.begin(), s.end(), 'b');
   v[2] = count(s.begin(), s.end(), 'c');

   sort(v.begin(), v.end());

   bool f = false;
   if (v[0] == v[1] && v[1] == v[2]) {
      f = true;
   }
   if (v[1] == v[2] && v[0]+1 == v[1]) {
      f = true;
   }
   if (v[0] == v[1] && v[1]+1 == v[2]) {
      f = true;
   }

   if (f) {
      puts("YES");
   } else {
      puts("NO");
   }

/*
   if (a == b && b == c) {
      puts("YES");
      return 0;
   }
   if (a == b && b == c+1) {
      puts("YES");
      return 0;
   }
   if (b == c) {
      if (a-1 == b) {
         puts("YES");
         return 0;
      }
   }
*/

   return 0;
}