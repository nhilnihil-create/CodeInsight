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
    
    string s;
    cin >> s;
    deque<char> q;
    for (char c : s) q.push_back(c);
    int ans = 0;
    while (sz(q) > 1) {
        char c1 = q.front();
        char c2 = q.back();
        if (c1 != c2) {
            if (c1 == 'x') {
                ans++;
                q.pop_front();
            } else if (c2 == 'x') {
                ans++;
                q.pop_back();
            } else {
                ans = -1;
                break;
            }
        } else {
            q.pop_front();
            q.pop_back();
        }
    }
    cout << ans << endl;
}