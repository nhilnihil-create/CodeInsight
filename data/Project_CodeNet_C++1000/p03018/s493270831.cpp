#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vs = vector<string>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    int n = s.size();
    ll ans = 0;
    ll cntA = 0;
    for (int i = 1; i < n; i++) {
        if (s[i-1] == 'B' && s[i] == 'C') {
            ans += cntA;
            i++;
        } else if (s[i-1] == 'A') {
            cntA++;
        } else {
            cntA = 0;
        }
    }
    cout << ans << endl;
}