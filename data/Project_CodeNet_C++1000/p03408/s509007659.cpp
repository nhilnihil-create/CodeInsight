#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

int main() {
    int N,M;
    cin >> N;
    map<string,int> s,t;
    REP(i,N) {
        string S; cin >> S; s[S]++;
    }
    cin >> M;
    REP(i,M) {
        string S; cin >> S; t[S]++;
    }
    int ans = 0;
    for(auto p : s) {
        if(t.count(p.first)) chmax(ans,p.second-t[p.first]);
        else chmax(ans,p.second);
    }
    cout << ans << endl;
}
