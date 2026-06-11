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

vector<int> start[100005];

int main(){
    int n, m;
    cin >> n >> m;
    vector<P> war(m);
    rep(i, m) {
        cin >> war[i].first >> war[i].second;
        war[i].first--; war[i].second--;
    }
    int ans = 0;
    sort(whole(war));
    
    rep(i, m) {
        start[war[i].second].push_back(war[i].first);
    }
    rep(i, n) {
        sort(whole(start[i]));
    }
    int pre = -1;
    rep(i, n) {
        if (start[i].size()==0) continue;
        int x = start[i].back();
        if (x>=pre) {
            ans++;
            pre = i;
        }
    }
    
    cout << ans << endl;
    return 0;
}
