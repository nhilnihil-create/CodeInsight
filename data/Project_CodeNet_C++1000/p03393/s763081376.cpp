#include "bits/stdc++.h"

using ll = long long;
using namespace std;

const int N = 2e9;

void solveCase() {


   string s;
   cin >> s;
   if(s.length() < 25) {
      cout << s;
      for(char c = 'a'; c <= 'z'; c++) {
         if(s.find(c) == string::npos) {
            cout << c;
            break;
         }
      }
      cout << endl;
   } else if(s == "zyxwvutsrqponmlkjihgfedcba") {
      cout << -1 << endl;
   } else {
      string t = s;
      next_permutation(s.begin(), s.end());
      for(int i = 1; i <= 26; i++) {
         if(s.substr(0, i) > t) {
            cout << s.substr(0, i) << endl;
            return;
         }
      }
      // cout << -1 << endl;
   }

}


int main() {
   cin.tie(0);
   cin.sync_with_stdio(0);
   
   int testcase = 1;
   // cin >> testcase;
 
   for(int i = 0; i < testcase; i++) {
      solveCase();
   }
 
   return 0;
}
