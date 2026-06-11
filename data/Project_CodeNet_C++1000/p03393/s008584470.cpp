#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr long long MOD = 1000000007;
constexpr long long INF = 1LL << 60;
const long double PI = acosl(-1.0);
constexpr long double EPS = 1e-11;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
int main(){
string s;
vector<ll> appear(26, 0);
cin >> s;
for (ll i = 0; i < s.size(); i++) {
    appear[s[i] - 'a']++;
}
if(s.size()<26){
    for (ll i = 0; i < 26; i++) {
        if(appear[i]==0){
            s += ('a' + i);
            break;
        }
    }
}
else{
    ll flag = 32;
    for (ll i = s.size() - 1; i > 0; i--) {
        if (s[i-1] < s[i]){
            flag = i;
            break;
        }
    }
    if (flag == 32){
        cout << -1 << endl;
        return 0;
    }
    string t = s.substr(flag, s.end() - s.begin() - flag+1);
    s.erase(s.begin() + flag, s.end());
    ll plus = INF;
    ll tt;
    for (ll i = 0; i < t.size(); i++) {
        tt = t[i]-'a';
        if (s[s.size()-1] < t[i]) chmin(plus, tt);
    }
    s.pop_back();
    s += ('a' + plus);
}
    cout << s << endl;
}