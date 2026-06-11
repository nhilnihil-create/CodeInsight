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
    string S; cin >> S;
    int N = S.size();
    string ans = "NO";
    REP(i,N) {
        for(int j = 0; j <= N - i; j++) {
            string tmp = S.substr(0,i) + S.substr(i+j,N-(i+j));
            if(tmp == "keyence") {
                ans = "YES";
            }
        }
    }
    cout << ans << endl;
} 