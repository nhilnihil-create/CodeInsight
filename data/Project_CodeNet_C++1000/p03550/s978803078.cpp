#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

int main(){
    int n, z, w;
    cin >> n >> z >> w;
    vector<int> v(n);
    rep(i, n) cin >> v[i];

    //全部取る
    int ans = abs(v[n-1] - w);
    //n-1枚取る
    if(n >= 2) chmax(ans, abs(v[n-2] - v[n-1]));

    cout << ans << endl;
}