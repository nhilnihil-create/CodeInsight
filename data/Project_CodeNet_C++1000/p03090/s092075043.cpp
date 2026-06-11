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
    if (n % 2 == 0) {
        cout << n * (n-2) / 2 << endl;
        for (int i = 1; i <= n; ++i) {
            for (int j = i+1; j <= n; ++j) {
                if (i + j == n+1) continue;
                cout << i << " " << j << endl;
            }
        }
    } else {
        cout << (n-1) * (n-1) / 2 << endl;
        for (int i = 1; i <= n; ++i) {
            for (int j = i+1; j <= n; ++j) {
                if (i + j == n) continue;
                cout << i << " " << j << endl;
            }
        }
    }
}