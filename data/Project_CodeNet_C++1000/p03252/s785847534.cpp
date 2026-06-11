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
    string s, t;
    cin >> s >> t;
    vector<char> a(26, -1), b(26, -1);
    bool flag = true;
    for (ll i = 0; i < s.size(); i++) {
        if(a[s[i]-'a']<0)a[s[i]-'a']=t[i];
        else{
            if (a[s[i]-'a'] != t[i]) flag = false;
        }
        if(b[t[i]-'a']<0)b[t[i]-'a']=s[i];
        else{
            if (b[t[i]-'a'] != s[i]) flag = false;
        }
    }
    cout << (flag ? "Yes" : "No") << endl;
}