 #include<bits/stdc++.h>
 
 using namespace std;
 typedef long long ll;
 #define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
 
 
 
 int main() {
     int n; cin >> n;
     string tmp;
     map<string, int> ma;
     rep(i, n) {
         cin >> tmp;
         ma[tmp]++;
     }
     int m; cin >> m;
     rep(i, m) {
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