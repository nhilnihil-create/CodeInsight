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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> sum(n);
    vector<int> rsum(n);
    rep(i, n) {
        if (i==0) {
            sum[i] = (s[i]=='W');
            continue;
        }
        sum[i] = sum[i-1] + (s[i]=='W');
    }
    for (int i=n-1; i>=0; i--) {
        if (i==n-1) {
            rsum[i] = (s[i]=='E');
            continue;
        }
        rsum[i] = rsum[i+1] + (s[i]=='E');
    }
    int ans = n+5;
    rep(i, n) {
        int res = 0;
        if (i>0) res += sum[i-1];
        if (i<n-1) res += rsum[i+1];
        chmin(ans, res);
    }
    
    cout << ans << endl;
    return 0;
}
