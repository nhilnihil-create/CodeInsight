#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x)  (x).begin(),(x).end()

typedef long long ll;
typedef pair<int,int> P;
typedef map<int,int> mp;

const int MOD = 1e9 + 7;


int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    ll N, M;
    string s, t;
    cin >> N >> M >> s >> t;

    ll tmp = __gcd(N, M);
    ll n = N / tmp;
    ll m = M / tmp;

    rep(i, tmp){
        if(s[i*n] != t[i*m]) {
            cout << -1 << endl;
            return 0;
        }
    }

    ll ans = N * M / tmp;
    cout << ans << endl;

    return 0;
}
