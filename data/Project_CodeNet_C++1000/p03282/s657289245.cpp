#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};


int main(){
    string s;
    cin >> s;
    ll k;
    cin >> k;
    int ans = 1;
    rep(i, k) {
        if (i==s.size()) break;
        if (s[i]!='1') {
            ans = s[i]-'0';
            break;
        }
    }
    
    cout << ans << endl;
    return 0;
}
