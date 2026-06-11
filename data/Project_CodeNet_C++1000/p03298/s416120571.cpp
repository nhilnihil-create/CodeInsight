#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

signed main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t = s;
    reverse(ALL(t));
    map<pair<string, string>, int> mp;
    for(int bit = 0; bit < 1 << n; bit++){
        string r,b;
        for(int i = 0; i < n; i++){
            if(bit & 1 << i){
                r.push_back(s[i]);
            }else{
                b.push_back(s[i]);
            }
        }
        mp[pair<string, string>(r, b)]++;
    }
    ll ans = 0;
    for(int bit = 0; bit < 1 << n; bit++){
        string r,b;
        for(int i = 0; i < n; i++){
            if(bit & 1 << i){
                r.push_back(t[i]);
            }else{
                b.push_back(t[i]);
            }
        }
        ans += mp[pair<string, string>(r, b)];
    }
    cout << ans << endl;
    return 0;
}   