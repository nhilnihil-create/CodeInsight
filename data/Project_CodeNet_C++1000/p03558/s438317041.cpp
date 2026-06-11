#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) rep(i, 0, n)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define int long long
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef pair<int, int> P;
const int mod = 1000000007;
const int INF = 1e12;

int d[100010];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin >> k;
    rep(i, 0, k) d[i] = INF;
    deque<P> dq;
    dq.push_back(P(1, 0));
    d[1] = 0;
    while(dq.size()){
        P p = dq.front(); dq.pop_front();
        if(p.first == 0) break;
        int nxt1 = (p.first + 1) % k;
        // cout << p.first << " " << p.second << endl;
        if(d[nxt1] > p.second + 1){
            d[nxt1] = p.second + 1;
            dq.push_back(P(nxt1, p.second + 1));
        }
        int nxt2 = (p.first * 10) % k;
        if(d[nxt2] > p.second){
            d[nxt2] = p.second;
            dq.push_front(P(nxt2, p.second));
        }
    }
    cout << d[0] + 1 << endl;
}