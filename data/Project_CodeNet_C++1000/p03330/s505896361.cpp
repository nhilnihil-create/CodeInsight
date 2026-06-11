#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VP = vector<P>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }


int D[32][32];
int C[502][502];
int RC[3][32];

const ll INF = 1LL << 60;

ll f(int c, int r, int y){
    ll res = 0;
    rep(x, c){
        res += D[x][y] * RC[r][x];
    }
    return res;
}

int main(){
    int n, c;
    cin >> n >> c;
    rep(i,c) rep(j,c){
        cin >> D[i][j];
    }
    rep(i, n) rep(j,n){
        cin >> C[i][j];
        C[i][j]--;
    }

    rep(i, n) rep(j, n){
        int r = (i + j + 2) % 3;
        int col = C[i][j];
        RC[r][col]++;
    }

    ll ans = INF;
    rep(y0, c){
        rep(y1, c){
            if (y0 == y1) continue;
            rep(y2, c){
                if (y0 == y2 || y1 == y2) continue;
                ll sum = 0;
                sum += f(c, 0, y0);
                sum += f(c, 1, y1);
                sum += f(c, 2, y2);
                ans = min(ans, sum);
            }
        }
    }
    cout << ans << endl;
    return 0;
}