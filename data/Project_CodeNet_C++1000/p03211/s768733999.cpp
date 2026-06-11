#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
   string s;
   cin >> s;
   ll ans = INT_MAX;
   for(ll i = 0; i < s.length() - 2; ++i){
        ans = min(ans, abs(753LL - stoi(s.substr(i, 3))));
   }
   cout << ans;
   return 0;
}
