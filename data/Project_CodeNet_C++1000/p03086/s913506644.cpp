#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 2e9
#define LINF 1e18
#define MOD 1000000007
#define PI 3.141592653589793
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define input(x, n)for(ll i = 0; i <(ll)(n); i++)cin >> x[i];
#define until(i,n) for(ll i = 1; i <= (ll)(n); i++)
#define all(x) (x).begin(),(x).end()
#define dump(x) cout << #x << "=" << (x) << endl
#define YES(n) cout << ((n) ? "YES" : "NO") << endl
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl

int main(){

    string s;
    ll cnt = 0;
    ll ans = 0;
    cin >> s;

    rep(i, s.length()){
        if(s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T')cnt++;
        else {
            ans = max(cnt, ans);
            cnt = 0;
        }
    }

    ans = max(cnt, ans);
    cout << ans << endl;

}