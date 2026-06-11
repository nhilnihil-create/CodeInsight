#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int main(){
    ios::sync_with_stdio(false);
    string s,t;
    cin >> s >> t;
    for(char i = 'a'; i <= 'z'; i++) {
        vector<int> idx1, idx2;
        rep(j, s.size()) if(s[j] == i) idx1.push_back(j);
        rep(j, t.size()) if(t[j] == i) idx2.push_back(j);
        rep(j, idx1.size()) if (t[idx1[0]] != t[idx1[j]]) {
            cout << "No" << endl;
            return 0;
        }
        rep(j, idx2.size()) if (s[idx2[0]] != s[idx2[j]]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}