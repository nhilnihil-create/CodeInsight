#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;


int main(){
    ll m, k;
    cin >> m >> k;
    vector<ll> tmp;

    if (m == 0){
        if (k==0) cout << 0 << " " << 0 << endl;
        else cout << -1 << endl;
        return 0;
    }
    else if (m == 1){
        if (k == 0) cout << 0 << " " << 0 << " " << 1 << " " << 1 << endl;
        else cout << -1 << endl;
        return 0;
    }
    else if (1<<m <= k){
        cout << -1 << endl;
        return 0;
    }

    rep(i, 1<<m){
        if(i!=k) tmp.push_back(i);
    }

    rep(i, tmp.size()) cout << tmp[i] << " ";
    cout << k << " ";
    rrep(i, tmp.size()) cout << tmp[i] << " ";
    cout << k << endl;

    return 0;
}
