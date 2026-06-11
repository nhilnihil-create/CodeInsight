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
    unordered_map<char,vector<char>> m;
    unordered_map<char,vector<char>> n;
    rep(i,s.length()){
        if(find(m[s[i]].begin(),m[s[i]].end(),t[i]) == m[s[i]].end())m[s[i]].push_back(t[i]);
        if(find(n[t[i]].begin(),n[t[i]].end(),s[i]) == n[t[i]].end())n[t[i]].push_back(s[i]);
    }
    for(auto a : m){
        if(a.second.size() >= 2){
            cout << "No\n";
            return 0;
        }
    }
    for(auto a : n){
        if(a.second.size() >= 2){
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}