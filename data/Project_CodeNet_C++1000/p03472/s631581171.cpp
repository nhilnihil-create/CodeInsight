#include <bits/stdc++.h>
using namespace std;
 
using ll=long long;
 
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
const ll MOD = 1e9 + 7;


int main() {
    int n; ll h;
    cin >> n >> h;
    vector<int> bs;
    ll maxa = 0; 
    rep(i, n) {
        ll a, b; cin >> a >> b;
        maxa = max(a, maxa);
        bs.push_back(b); 
    }
    sort(all(bs), greater<int>());
    int cnt = 0; 
    rep(i, n) {
        if (bs[i] < maxa) break;
        h -= bs[i];
        ++cnt;
        if (h <= 0) break;
    } 
    if (h > 0) cnt += (h+maxa-1) / maxa; 
    cout << cnt << endl;
    return 0;
}