#include<bits/stdc++.h>
#define forr(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define ALL(a) (a.begin()),(a.end())
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll, ll> LP;
const ll LINF = 1LL<<60;
const int INF = 1001001001;
const int MOD = 1000000007;

/* --------------------------------------------------- */

int main() {
    int n;
    cin >> n;
    unordered_map<int, int> mp;
    ll ans = 0;
    rep(i, n) {
        int a;
        cin >> a;
        mp[a]++;
        if(mp[a] > a) ans++;
    }
    for(auto it = mp.begin(); it != mp.end(); it++) {
        if(it->first > it->second) ans += it->second;
    }
    cout << ans << endl;

    return 0;
}