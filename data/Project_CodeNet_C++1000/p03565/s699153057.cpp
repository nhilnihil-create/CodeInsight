#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    string s,t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    string ans = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
    for(int i = 0;i+m<=n;i++) {
        bool ok = true;
        // tを部分文字列として含むか判定
        rep(j,m) {
            if(s[i+j] == '?') continue;
            if(s[i+j] != t[j]) ok = false;
        }
        if(!ok) continue;
        //t以外の?はaにしてその辞書順最小をとる
        string u = s;
        
        rep(j,m) {
            u[i+j] = t[j];
        }
        rep(j,n) {
            if(u[j] == '?') u[j] = 'a';
        }
        // cout << u << endl;
        ans = min(ans,u);
    }
    if(ans == "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz") {
        cout << "UNRESTORABLE" << endl;
        return 0;
    }
    cout << ans << endl;
}