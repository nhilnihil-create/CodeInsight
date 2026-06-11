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
    ll a, b, c, k;
    cin >> a >> b >> c >> k;
    int p;
    if (k % 2 == 0) p = 1;
    else p = -1;
    cout << (a - b) * p << endl;
    return 0;
}