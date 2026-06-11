#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vout(x) {rep(a,x.size()) cout << x[a] << " "; cout << endl;}
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 2e5;

int main() {
    ll k, a, b; cin >> k >> a >> b;
    k++;
    if (b <= a+2) cout << k << endl;
    else {
        k -= a;
        ll ans = a;
        while (true) {
            ll ct = ans/a;
            ct = min(ct,k/2);
            if (ct == 0) break;
            k -= 2*ct;
            ans = (ans-ct*a)+ct*b;
        }
        cout << ans+k << endl;
    }
}