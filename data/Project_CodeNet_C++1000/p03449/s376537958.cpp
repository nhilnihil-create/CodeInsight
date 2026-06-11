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
    int n;
    cin >> n;
    vector<int> sum1(n);
    vector<int> sum2(n);
    vector<int> a1(n);
    vector<int> a2(n);
    rep(i, n) cin >> a1[i];
    rep(i, n) cin >> a2[i];
    rep(i, n) {
        if (i==0) sum1[i] = a1[i];
        else sum1[i] = sum1[i-1] + a1[i];
    }
    for (int i=n-1; i>=0; i--) {
        if (i==n-1) sum2[i] = a2[i];
        else sum2[i] = sum2[i+1] + a2[i];
    }
    int ans = 0;
    rep(i, n) {
        int now = sum1[i] + sum2[i];
        chmax(ans, now);
    }
    
    cout << ans << endl;
    return 0;
}
