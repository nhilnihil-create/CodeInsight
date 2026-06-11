#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>

using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pii>v(m);
    rep(i, 0, m){
        cin >> v[i].first >> v[i].second;
        v[i].second *= -1;
    }
    sort(v.begin(), v.end());
    rep(i, 0, m){
        v[i].second *= -1;
    }
    int ans = 1;
    int end = v[0].second;
    rep(i, 0, m){
        if(v[i].first < end){
            end = min(end, v[i].second);
            continue;
        }
        ans++;
        end = v[i].second;
    }
    cout << ans << endl;
}