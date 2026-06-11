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
    int n = s.size();
    
    string ans = "AC";
    if (s[0]!='A') ans = "WA";
    map<char, int> mp;
    rep(i, n) {
        if (i<=1) continue;
        if (i==n-1) continue;
        mp[s[i]]++;
    }
    if (mp['C']!=1) ans = "WA";
    rep(i, n) {
        if (s[i]=='A' || s[i]=='C') continue;
        if (s[i]<'a' || s[i]>'z') ans = "WA";
    }
    
    cout << ans << endl;
    return 0;
}
