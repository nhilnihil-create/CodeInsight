#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;


ll dist[100010];
int l[100010], r[100010];


int main(){
    int h, w, d;
    cin >> h >> w >> d;


    vector<P> b(h * w + 1);
    rep(i, h){
        rep(j, w){
            int a;
            cin >> a;
            P p;
            p = make_pair(j, i);
            b[a] = p;
        }
    }

    int q;
    cin >> q;
    rep(i, q) cin >> l[i] >> r[i];


    for(int i = 1; i <= h * w; i++){
        if (i <= d) dist[i] = 0;
        else dist[i] = dist[i - d] + abs(b[i].first - b[i - d].first) + abs(b[i].second - b[i - d].second);
    }

    // rep(i, h*w){
    //     cout << i + 1 << " " << dist[i + 1] << endl;
    // }


    rep(i, q){
        cout << dist[r[i]] - dist[l[i]] << endl;
    }


    return 0;
}