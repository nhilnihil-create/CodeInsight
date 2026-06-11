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
const int INF = 1001001001;


int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a;
    vector<int> b;
    rep(i, n) {
        int x;
        cin >> x;
        if (x>=0) a.push_back(x);
        else b.push_back(-x);
    }
    sort(whole(a));
    sort(whole(b));
    int ans = INF;
    rep(i, k+1) {
        int l = i;
        int r = k-i;
        if (l>a.size() || r>b.size()) continue;
        int ia = 0, ib = 0;
        if (l>0) ia = a[l-1];
        if (r>0) ib = b[r-1];
        chmin(ans, ia*2+ib);
        chmin(ans, ib*2+ia);
    }
    
    
    cout << ans << endl;
    return 0;
}
