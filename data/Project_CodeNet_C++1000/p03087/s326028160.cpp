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
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};


int main(){
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> v;
    rep(i, n) {
        if (i==0) continue;
        if (s[i-1]=='A' && s[i]=='C') v.push_back(i);
    }
    
    rep(i, q) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        auto it1 = lower_bound(whole(v), l+1);
        auto it2 = upper_bound(whole(v), r);
        it2--;
        int ans = it2 - it1 + 1;
        cout << ans << endl;
    }
    return 0;
}
