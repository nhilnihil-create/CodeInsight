#include <bits/stdc++.h>
#define rep(i,l,r)for(int i=(l);i<(r);i++)
const int INF = 2147483647;//int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//ミョ(-ω- ?)
int main() {
    string s;
    cin >> s;
    cout << fixed;
    ll di = s.length();
    int top = s[0] - '0';
    rep(i,1,di){
        if(s[i] != '9'){
            cout << top + 9*(di-1)-1 << endl;
            return 0;
        }
    }
    cout << top + 9*(di-1) << endl;
    return 0;
}