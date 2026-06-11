#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

int a[303][303];
int posx[90001];
int posy[90001];
int cost[303][303];
int f(int from,int to){
    int fx = posx[from];
    int fy = posy[from];
    int tx = posx[to];
    int ty = posy[to];
    return abs(fx-tx) + abs(fy-ty);
}
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int h,w,d;
    cin >> h >> w >> d;
    rep(i,h)rep(j,w){
        cin >> a[i][j];
        int now = a[i][j];
        posx[now] = i;
        posy[now] = j;
    }
    vector<vector<ll>> memo(d+1);

    for(int i=1;i<=d;i++){
        int start = i;
        memo[i].push_back(0);
        for(int j=start;j+d<=h*w;j+=d){
            memo[i].push_back(memo[start].back()+f(j,j+d));
        }
    }

    int q;
    cin >> q;
    rep(i,q){
        ll ans = 0;
        int l,r;
        cin >> l >> r;
        int type;
        if(l%d==0 || r % d == 0)type = d;
        else type = l%d;
        cout << memo[type][(r-type)/d] - memo[type][(l-type)/d] << endl;
    }
}