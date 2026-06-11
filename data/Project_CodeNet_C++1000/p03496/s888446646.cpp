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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<P> ans;
    int x = -1;
    int index = 0;
    rep(i, n) {
        if (abs(a[i])>x) {
            x = abs(a[i]);
            index = i;
        }
    }

    rep(i, n) {
        if ((ll)a[i]*a[index]<0) {
            ans.emplace_back(index+1, i+1);
        }
    }
    if (a[index]>=0) {
        rep(i, n-1) {
            ans.emplace_back(i+1, i+2);
        }
    }
    else {
        for (int i=n-1; i>=1; i--) {
            ans.emplace_back(i+1, i);
        }
    }
    int m = ans.size();
    cout << m << endl;

    
    rep(i, m) cout << ans[i].first << " " << ans[i].second << endl;
    return 0;
}
