#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    string s,t;
    cin >> s >> t;
    vector<ll>scnt(26,0);
    vector<ll>tcnt(26,0);
    for(ll i=0;i<s.size();i++){
        scnt[s[i]-'a']++;
        tcnt[t[i]-'a']++;
    }
    sort(scnt.begin(),scnt.end());
    sort(tcnt.begin(),tcnt.end());
    bool judge=true;
    for(ll i=0;i<scnt.size();i++){
        if(scnt[i]!=tcnt[i]){
            judge=false;
        }
    }
    if(judge) cout << "Yes" << endl;
    else cout << "No" << endl;
}