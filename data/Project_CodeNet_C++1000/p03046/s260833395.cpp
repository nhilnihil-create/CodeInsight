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


int main(){
    int m, k;
    cin >> m >> k;
    if (k>=1<<m) {
        cout << "-1" << endl;
        return 0;
    }
    if (m==0) {
        cout << "0 0" << endl;
        return 0;
    }
    if (m==1) {
        if (k==1) {
            cout << "-1" << endl;
            return 0;
        }
        cout << "0 0 1 1" << endl;
        return 0;
    }
    rep(i, 1<<m) {
        if (i==k) continue;
        cout << i << " ";
    }
    cout << k << " ";
    for (int i=(1<<m)-1; i>=0; i--) {
        if (i==k) continue;
        cout << i << " ";
    }
    cout << k << endl;

    return 0;
}
