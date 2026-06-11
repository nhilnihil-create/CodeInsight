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
    vector<int> a(n/2);
    vector<int> b(n/2);
    rep(i, n) {
        if (i%2==0) cin >> a[i/2];
        else cin >> b[i/2];
    }
    map<int, int> ma;
    map<int, int> mb;
    int x1 = 0, y1 = 0;
    int x2 = 0, y2 = 0;
    rep(i, n/2) {
        ma[a[i]]++;
        mb[b[i]]++;
    }
    vector<P> va;
    vector<P> vb;
    for(auto m: ma) {
        va.push_back(m);
    }
    for (auto m: mb) {
        vb.push_back(m);
    }
    auto comp = [](P a, P b) {
        return a.second>b.second;
    };
    sort(whole(va), comp);
    sort(whole(vb), comp);
    int ans = 0;
    if (va[0].first!=vb[0].first) {
        ans = n - va[0].second - vb[0].second;
    }
    else {
        if (va.size()==1 && vb.size()==1) ans = n/2;
        else if (va.size()==1) {
            ans = n - va[0].second - vb[1].second;
        }
        else if (vb.size()==1) {
            ans = n - va[1].second - vb[0].second;
        }
        else {
            ans = n - va[0].second - vb[1].second;
            chmin(ans, n - va[1].second - vb[0].second);
        }
    }

    
    cout << ans << endl;
    return 0;
}
