#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rep1(i, n) FOR(i, 1, n+1)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define whole(x) (x).begin(),(x).end()
#define rwhole(x) (x).rbegin(), (x).rend()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define P pair<int, int>
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define eb emplace_back
#define pr(s) cout << (s) << '\n'
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> sw(n+1), sb(n+1);
    rep(i, n) {
        if (s[i]=='.') {
            sw[i+1] = sw[i] + 1;
            sb[i+1] = sb[i];
        }
        else {
            sb[i+1] = sb[i] + 1;
            sw[i+1] = sw[i];
        }
    }
    int ans = n+5;
    rep(i, n+1) {
        int x = sb[i];
        int y = sw[n] - sw[i];
        chmin(ans, x+y);
    }
    
    pr(ans);
    return 0;
}
