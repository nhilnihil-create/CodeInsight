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
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
const int INF = 1001001001;

map<int, int> mp;
int f(int x) {
    if (x<=5) return x;
    if (mp.count(x)) return mp[x];
    int a = 6;
    int b = 9;
    int res = x;
    while (x>=a) {
        chmin(res, f(x-a)+1);
        a *= 6;
    }
    while (x>=b) {
        chmin(res, f(x-b)+1);
        b *= 9;
    }
    mp[x] = res;
    return res;
}


int main(){
    int n;
    cin >> n;
    int ans = f(n);
    
    cout << ans << endl;
    return 0;
}
