#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep2(i,s,n) for (int i = s; i < n; ++i)
#define all(a) a.begin(),a.end()
#define tmax(a,b,c) max(a,max(b,c))
#define tmin(a,b,c) min(a,min(b,c))
#define pb push_back
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a,T b) {if(a > b){a = b; return true;} return false;}
template<class T> inline bool chmax(T& a,T b) {if(a < b){a = b; return true;} return false;}
const int inf = 1001001001;
const ll linf = 1001001001001001001;

int main() {
    string s;
    cin >> s;
    if(s.size() != 26) {
        vector<bool> ex(26,false);
        for(char c : s) ex[c-'a'] = true;
        cout << s;
        rep(i,26) if(!ex[i]) {
            char c = 'a'+i;
            cout << c << endl;
            return 0;
        }
    } else {
        for(int i = 24; i >= 0; i--) {
            char c = s[i];
            bool ok = false;
            rep2(j,i+1,26) {
                if(s[j] > c) ok = true;
            }
            if(ok) {
                cout << s.substr(0,i);
                string ns = s.substr(i);
                char nc = 'z';
                rep2(j,1,ns.size()) if(ns[j] > c) chmin(nc,ns[j]);
                cout << nc << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
}