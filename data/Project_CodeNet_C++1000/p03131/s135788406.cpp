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
    ll K,A,B;
    cin >> K >> A >> B;
    if(A+2 >= B || K+1 < A) cout << K+1 << endl;
    else {
        ll rest = K+1-A;
        if(rest%2 == 0) cout << rest/2*B-(rest/2-1)*A << endl;
        else cout << rest/2*B-(rest/2-1)*A+rest%2 << endl;
    }
}