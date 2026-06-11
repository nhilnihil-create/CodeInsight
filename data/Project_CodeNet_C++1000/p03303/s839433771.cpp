#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    string s;
    cin >> s;
    ll w;
    cin >> w;
    string ans="";
    for(ll i=0;i<s.size();i+=w){
        ans.push_back(s[i]);
    }
    cout << ans << endl;
}