#include <bits/stdc++.h>
using namespace std;

int main(){
   int n; cin >> n;
   map<string, int> s;

   for (int i = 0; i < n; i ++) {
      string tmp; cin >> tmp;
      if (s.count(tmp) == 0) {
         s[tmp] = 1;
      } else {
         s[tmp] ++;
      }
   }

   int m; cin >> m;
   for (int i = 0; i < m; i ++) {
      string tmp; cin >> tmp;
      if (s.count(tmp) == 0) {
         s[tmp] = -1;
      } else {
         s[tmp] --;
      }
   }

   int max = -101;
   for (map<string, int>::iterator itr = s.begin(); itr != s.end(); ++itr) {
      if(itr->second > max) {
         max = itr->second;
      }
   }
   if (max < 1) {
      cout << 0 << endl;
   } else {
      cout << max << endl;
   }
   return 0;
}
