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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<P> v;
    
    P now;
    rep(i, n) {
        if (i==0) {
            if (s[i]=='1') now.first = -1;
            else v.emplace_back(-1, -1);
        }
        if (i>0 && s[i]=='1' && s[i-1]=='0') now.first = i;
        if (i<n-1 && s[i]=='1' && s[i+1]=='0') {
            now.second = i;
            v.push_back(now);
        }
        if (i==n-1) {
            if (s[i]=='1') {
                now.second = n;
                v.push_back(now);
            }
            else {
                v.emplace_back(n, n);
            }
        }
    }
    
    if (k>=v.size()-1) {
        cout << n << endl;
        return 0;
    }
    int l = 0;
    int r = k;
    int ans = 0;
    while (r<=v.size()-1) {
        int res = v[r].second - v[l].first + 1;
        if (v[r].second==n) res--;
        if (v[l].first==-1) res--;
        ans = max(res, ans);
        l++; r++;
    }
    


    
    cout << ans << endl;
    return 0;
}
