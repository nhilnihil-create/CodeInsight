#include <bits/stdc++.h>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define debug(x) cerr << #x << ": " << x << endl

using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct Edge{int from, to; ll cost;};

const ll MOD = 1000000007;
const long double EPS = 10e-10;

int main(){
    int n; ll ans = 0;
    cin >> n;
    vector<ll> l(n+1, 0), r(n+1, 0);
    rep(n) cin >> l[i] >> r[i];
    sort(rall(l)); sort(all(r));


    rep(n){
        if(l[i] - r[i] <= 0) break;
        ans += l[i] - r[i];
    }

    cout << 2*ans << endl;
}
