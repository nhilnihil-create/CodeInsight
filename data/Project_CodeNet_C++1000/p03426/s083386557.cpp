#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;
typedef pair<int, int> P;

const ll mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INF = 1152921504606846976

int main()
{
    int h,w,d; cin >> h >> w >> d;
    int a[h][w]; rep(i,h) rep(j,w) cin >> a[i][j];
    int q; cin >> q;
    vector<pair<int,pair<int,int> > > g[d];
    vector<int> sum[d];
    rep(i,h) {
        rep(j,w){
            g[a[i][j] % d].push_back(make_pair(a[i][j],make_pair(i,j)));
        }
    }
    rep(i,d){
        sort(g[i].begin(),g[i].end());
    }
    rep(i,d){
        sum[i].push_back(0);
        rep(j,g[i].size()-1){
            sum[i].push_back(abs(g[i][j+1].second.first - g[i][j].second.first )+abs(g[i][j+1].second.second - g[i][j].second.second));
        }
    }
    rep(i,d){
        rep(j,g[i].size()-1){
            sum[i][j+1] += sum[i][j];
        }
    }
    rep(i,q){
        int l,r; cin >> l >> r;
        int tmp = l % d;
        cout << sum[tmp][(r-1)/d] - sum[tmp][(l-1)/d] << endl;
    }
}
