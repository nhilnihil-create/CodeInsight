#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
using Graph = vector<vector<int>>;

int main() {
     int n; cin >> n;
     string tmp;
     map<string, int> ma;
     FOR(i,0,n) {
         cin >> tmp;
         ma[tmp]++;
     }
     int m; cin >> m;
     FOR(i,0,m) {
         cin >> tmp;
         ma[tmp]--;
     }
 
     int ans = 0;
     for(auto itr : ma) {
         ans = max(itr.second, ans);
     }
 
     cout << ans << endl;
 
     return 0;
     
 }