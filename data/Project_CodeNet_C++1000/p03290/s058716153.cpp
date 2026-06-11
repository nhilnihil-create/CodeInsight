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
const int INF = 1001001001;

int main(){
    int d, g;
    cin >> d >> g;
    vector<int> p(d), c(d);
    rep(i, d) cin >> p[i] >> c[i];
    int ans = INF;
    rep(i, 1<<d) {
        vector<bool> comp(d);
        int score = g;
        int num = 0;
        rep(j, d) {
            if (i>>j&1) {
                comp[j] = true;
                score -= (c[j]+100*(j+1)*p[j]);
                num += p[j];
            }
        }
        int index = d-1;
        //debug(score);
        while (score>0 && index>=0) {
            if (comp[index]) {
                index--;
                continue;
            }
            int v = min(score, 100*(index+1)*(p[index]-1));
            score -= v;
            num += (v-1)/(100*(index+1))+1;
            index--;
        }
        if (score<=0) {
            chmin(ans, num);
        }
    }
    
    
    cout << ans << endl;
    return 0;
}
