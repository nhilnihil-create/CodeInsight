#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
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
    int n, h;
    cin >> n >> h;
    vector<int> a(n);
    vector<int> b(n);
    rep(i, n) cin >> a[i] >> b[i];
    sort(whole(a));
    sort(whole(b));
    reverse(whole(a));
    reverse(whole(b));
    int ans = 0;
    int maxa = a[0];
    int index = 0;
    while (index<n && h>0 && b[index]>maxa) {
        h -= b[index];
        index++;
        ans++;
    }
    //debug(ans);
    //debug(h);
    if (h>0) {
        ans += ((h-1)/maxa+1);
    }
    
    cout << ans << endl;
    return 0;
}
