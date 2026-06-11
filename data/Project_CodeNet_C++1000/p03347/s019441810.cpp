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

ll a[200010];

int main(){
    int n;
    cin >> n;
    rep(i, n) cin >> a[i];

    if (a[0] != 0){
        cout << -1 << endl;
        return 0;
    }

    ll now = 0, cnt = 0;
    bool flag = true;
    for (int i = 1; i < n; i++){
        if (a[i] - a[i-1] > 1) flag = false;
        else if (a[i] == a[i-1] + 1) cnt++;
        else cnt += a[i];
    }

    if (!flag) cout << -1 << endl; 
    else cout << cnt << endl;

    return 0;
}