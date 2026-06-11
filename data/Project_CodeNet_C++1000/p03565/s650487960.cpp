#include <bits/stdc++.h>
#define repp(i,l,r)for(long long i=(l);i<(r);i++)
#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define per(i,n) for (long long i = (n); i >= 0; --i)
const int INF = 2147483647;//int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//ミョ(-ω- ?)
int main() {
    string s,t;
    cin >> s >> t;
    string res = string(s.length(),'z');
    bool isAnser = false;
    if(s.length() < t.length()){
        cout << "UNRESTORABLE" << endl;
        return 0;
    }
    rep(i,s.length() - t.length() + 1){
        bool b = true;
        rep(j,t.length()){
            if(s[i+j] != '?' && s[i+j] != t[j]){
                b = false;
                break;
            }
        }
        if(b){
            string ans = "";
            repp(j,0,i){
                if(s[j] != '?')ans += s[j];
                else ans += 'a';
            }
            ans += t;
            repp(j,i + t.length(),s.length()){
                if(s[j] != '?')ans += s[j];
                else ans += 'a';
            }
            isAnser = true;
            chmin(res,ans);
        }
    }
    if(isAnser)cout << res << endl;
    else cout << "UNRESTORABLE" << endl;
    return 0;
}