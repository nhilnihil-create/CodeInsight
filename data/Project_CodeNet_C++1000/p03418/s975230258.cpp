#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1 << 21;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

// 090d
int main(){
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    if (k==0) {
        cout << n*n << endl;
        return 0;
    }
    for(int b=k+1; b<=n; b++){
        ans += ((n+1)/b)*(b-k);
        if ((n+1)%b==0) continue;
      	ans += max(n%b-k+1, 0LL);
    }
    cout << ans << endl;
    return 0;
}