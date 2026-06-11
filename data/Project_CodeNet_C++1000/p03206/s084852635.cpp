//url:
//problem name: 

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
    int D; cin >> D;
    D %= 10;
    string ans;
    if(D == 5) ans = "Christmas";
    if(D == 4) ans = "Christmas Eve";
    if(D == 3) ans = "Christmas Eve Eve";
    if(D == 2) ans = "Christmas Eve Eve Eve";
    cout << ans << endl;
}
