#include <bits/stdc++.h>
#define itn int
#define REP(i, n) for (ll i = 0; i < n; i++)
#define IREP(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = a; i < b + 1; i++)
#define all(v) v.begin(), v.end()
#define SENTINEL 2000000000
#define NIL -1
using namespace std;
typedef long long ll;

const ll MAX = 510000;
const ll INF = 1LL << 60;
const ll MOD = 1000000007;
template <class T>inline bool chmin(T &a, T b){if(a>b){a=b;return true;}return false;}
template <class T>inline bool chmax(T &a, T b){if(a<b){a=b;return true;}return false;}

int n, a, b, c;
vector<int> l(8);
int solve(int now,int x,int y,int z,int w){
    if(now==n){
        if(x*y*z==0){
            return 100000;
        }
        return abs(a-x)+abs(b-y)+abs(c-z)+(w-3)*10;
    }
    return min({solve(now + 1, x + l[now], y, z,w+1), solve(now + 1, x, y + l[now], z,w+1), solve(now + 1, x, y, z + l[now],w+1), solve(now + 1, x, y, z,w)});
}
int main()
{
    cin >> n >> a >> b >> c;
    REP(i,n){
        cin >> l[i];
    }
    cout << solve(0,0,0,0,0) << endl;
}
