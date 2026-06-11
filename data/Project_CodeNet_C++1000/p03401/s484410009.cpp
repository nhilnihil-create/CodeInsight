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
    vector<int> a(n+2);
    int sum = 0;
    rep(i, n) {
        cin >> a[i+1];
    }
    rep(i, n+1) {
        sum += abs(a[i]-a[i+1]);
    }
    
    
    rep(i, n) {
        int ans = sum;
        ans -= abs(a[i+1]-a[i]);
        ans -= abs(a[i+1]-a[i+2]);
        ans += abs(a[i]-a[i+2]);
        cout << ans << endl;
    }
    return 0;
}
