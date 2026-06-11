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


int main(){
    int x;
    cin >> x;
    vector<bool> v(1005);
    v[1] = true;
    for (int i=2; i<=31; i++) {
        int now = i*i;
        while (now<=1000) {
            v[now] = true;
            now *= i;
        }
    }
    int ans = 0;
    for (int i=x; i>=1; i--) {
        if (v[i]) {
            ans = i;
            break;
        }
    }
    
    cout << ans << endl;
    return 0;
}
