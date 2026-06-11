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
    string s;
    cin >> s;
    int n = s.size();
    int k;
    cin >> k;
    vector<string> v;
    map<string, int> mp;
    rep(i, n) {
        string now;
        rep(j, 5) {
            if (i+j>=n) continue;
            now += s[i+j];
            if (!mp.count(now)) {
                v.push_back(now);
                mp[now]++;
            }
        }
    }
    sort(whole(v));
    string ans = v[k-1];
    
    cout << ans << endl;
    return 0;
}
