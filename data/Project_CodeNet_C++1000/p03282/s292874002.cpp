#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    string s;
    cin >> s;
    ll k;
    cin >> k;
    int ans;
  	ll n=s.size();
    if(k<=n){
        for(int i=0;i<k;i++){
            if(s[i]!='1'){
                ans=s[i]-'0';
                break;
            }
            if(s[k-1]=='1'){
                ans=1;
            }
        }
    }
    else {
        for(int i=0;i<s.size();i++){
            if(s[i]!='1'){
                ans=s[i]-'0';
                break;
            }
        }
    }
    cout << ans << endl;
}
