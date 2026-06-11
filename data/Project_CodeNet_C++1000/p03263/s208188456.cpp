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


int h, w;

pair<int, int> nextxy(int x, int y){
    int nx, ny;
    if (y % 2 == 0){
        if (x < w - 1) nx = x + 1, ny = y;
        else nx = x, ny = y + 1;
    }
    else {
        if (0 < x) nx = x - 1, ny = y;
        else nx = x, ny = y + 1;    
    }
    return make_pair(nx, ny);
}

int a[505][505];

int main(){
    cin >> h >> w;
    rep(i, h) rep(j, w) cin >> a[i][j];

    vector<pair<int,int>> from;
    vector<pair<int,int>> to;

    int x = 0, y = 0;
    while(true){
        pair<int, int> p = nextxy(x, y);
        int nx = p.first;
        int ny = p.second;
        if (ny == h) break;

        if (a[y][x] % 2 != 0){
            a[y][x]--;
            a[ny][nx]++;
            from.push_back(make_pair(y, x));
            to.push_back(make_pair(ny, nx));
        }
        x = nx, y = ny;
    }
    
    cout << from.size() << endl;
    rep(i, from.size()){
        cout << from[i].first + 1 << " " << from[i].second + 1 << " ";
        cout << to[i].first  + 1 << " " << to[i].second + 1 << endl;
    }

    return 0;
}