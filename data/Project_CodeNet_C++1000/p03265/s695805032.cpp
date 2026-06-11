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

P rotate (P p) {
    P res;
    res.first = -p.second;
    res.second = p.first;
    return res;
}


int main(){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    P p = P(x2-x1, y2-y1);
    int x3, y3, x4, y4;
    p = rotate(p);
    x3 = x2 + p.first;
    y3 = y2 + p.second;
    p = rotate(p);
    x4 = x3 + p.first;
    y4 = y3 + p.second;
    printf("%d %d %d %d\n", x3, y3, x4, y4);
    return 0;
}
