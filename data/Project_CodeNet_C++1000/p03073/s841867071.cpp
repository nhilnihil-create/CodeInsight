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
    string S; cin >> S;
    string s1 = "";
    string s2 = "";
    int N = S.size();
    REP(i,N) {
        s1 += (char)('0' + (i%2 == 0));
        s2 += (char)('0' + (i%2 != 0));
    }
    int ans1 = 0, ans2 = 0;
    REP(i,N) {
        ans1 += (s1[i] != S[i]);
        ans2 += (s2[i] != S[i]);
    }
    cout << min(ans1,ans2) << endl;
}