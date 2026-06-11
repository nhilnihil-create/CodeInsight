//url:
//problem name:

#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long,long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

int main() {
    string S;
    ll K;
    cin >> S >> K;
    if(K == 1) cout << S[0] << endl;
    else if(S[0] == '1') {
        int i = 1;
        while(S[i] == '1') i++;
        if(i >= K) cout << 1 << endl;
        else cout << S[i] << endl;
    }
    else cout << S[0] << endl;
}

