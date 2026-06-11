#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const double PI=acos(-1);

int main(){
    ll n;
    cin >> n;
    map<char, vector<string>> s;
    rep(i, n){
        string ss;
        cin >> ss;
        if(ss[0] == 'M' || ss[0] == 'A' || ss[0] == 'R' || ss[0] == 'C' || ss[0] == 'H'){
            s[ss[0]].push_back(ss);
        }
    }
    ll ans = 0;
        rep(i, s.size()){
            for(ll j = i+1; j < s.size(); ++j){
                for(ll k = j+1; k < s.size(); ++k){
                    ans += s[i].size() * s[j].size() * s[k].size();
                }
            }
        }
        cout << ans << endl;
    return 0;
}