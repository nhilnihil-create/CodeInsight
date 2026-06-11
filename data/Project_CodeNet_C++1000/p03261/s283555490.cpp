#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

int main() {
    int N;
    cin >> N;
    string pre;
    bool ok = true;
    map<string,int> mp;
    REP(i,N) {
        string W; cin >> W;
        if(i == 0) {
            pre = W;
            mp[W] = 1;
        } else {
            if(pre[pre.size()-1] != W[0]) {
                ok = false;
            } else if(mp.count(W)) {
                ok = false;
            } else {
                mp[W] = 1;
                pre = W;
            }
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
}
