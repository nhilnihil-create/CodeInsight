#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vc = vector<char>;
using vb = vector<bool>;
using vs = vector<string>;
using vll = vector<long long>;
using vp = vector<pair<int, int>>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvll = vector<vector<long long>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    int ans = 0;
    int enda = 0;
    int beginb = 0;
    int both = 0;
    rep(i, n) {
        string s;
        cin >> s;
        if (s.front() == 'B' && s.back() == 'A') both++;
        else if (s.front() == 'B') beginb++;
        else if (s.back() == 'A') enda++;
        
        rep(j, sz(s) - 1) {
            if (s[j] == 'A' && s[j+1] == 'B') ans++;
        }
    }
    if (both > 0 && enda > 0 && beginb > 0) {
        ans += both+1;
        enda--; beginb--;
        ans += min(enda, beginb);
    } else if (both == 0) {
        ans += min(enda, beginb);
    } else if (both > 0 && enda == 0 && beginb == 0) {
        ans += both-1;
    } else {
        ans += both;
    }
    cout << ans << endl;
}