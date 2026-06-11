#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    int k;
    cin >> s >> k;
   set<string> sub;
   int n = (int) s.size();
   for (int i = 0; i < n; i++) {
       for (int j = i; j < i + k && j < n; j++) {
           string x;
           for (int l = i; l <= j; l++) {
               x += s[l];
           }
           sub.insert(x);
       }
   }

   auto t = sub.begin();
   for (int i = 0; i < k - 1; i++) {
       t++;
   }
   cout << *t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
