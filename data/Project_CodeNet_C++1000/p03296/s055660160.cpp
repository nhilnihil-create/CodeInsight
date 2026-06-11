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

ll a[110];
int main(){
    int n;
    cin >> n;
    rep(i, n) cin >> a[i];
    int cnt = 0;
    rep(i, n - 1){
        if (a[i] == a[i+1]) {
            cnt++;
            a[i + 1] = 1e9 - i;
        }
    }

    cout << cnt << endl;
    return 0;
}