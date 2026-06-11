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

int main(){
    int n;
    int a, b;
    cin >> n >> a >> b;
    int p = 0, q = 0, r = 0;
    rep(i, n){
        int x;
        cin >> x;
        if (x <= a) p++;
        else if (x <= b) q++;
        else r++;
    }

    cout << min({p, q, r}) << endl;

    return 0;
}