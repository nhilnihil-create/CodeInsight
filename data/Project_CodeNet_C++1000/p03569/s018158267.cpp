#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll=long long;

int main(){
   string s;
   cin >> s;
   ll l=0,r=s.size()-1;
   ll ans=0;
   while (1) {
     if (l>=r) break;
     if (s[l]==s[r]){
            l++;r--;
     }
     else if (s[l]=='x'){
        ans++;
        l++;
     }
     else if (s[r]=='x'){
        ans++;
        r--;
     }
     else {
        ans=-1;
        break;
     }
   }
    cout << ans << endl;
    return 0;
}
