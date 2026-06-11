#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s, t;
    cin >> s >> t;
    int n = s.size();
    set<char> st;
    rep(i,n){
        if(s[i] == t[i]) st.insert(s[i]);
        else if(st.find(s[i]) != st.end() || st.find(t[i]) != st.end()){
            cout << "No" << endl;
            return 0;
        }
        else{
            st.insert(t[i]);
            char u = s[i];
            char v = t[i];
            for(int j = i; j < n; ++j){
                if(s[j] == u) s[j] = v;
                else if(s[j] == v) s[j] = u;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}
