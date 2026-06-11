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
    string S;
    cin >> S;
    int m = (S[5]-'0')*10 + (S[6]-'0');
    int d = (S[8]-'0')*10 + (S[9]-'0');
    bool ok = true;
    if(m < 4) ok = false;
    else if(m == 4 && d <= 30) ok = false;
    cout << (!ok ? "Heisei":"TBD") << endl;
}
