#include<bits/stdc++.h>
#define taskname "A"
#define pb push_back
#define mp make_pair
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
const int maxn = 2e5 +5;
const int inf = 1e9 + 1;
const ll llinf = 1e18 + 5;
int n , a[maxn];
int x;
ll s[maxn];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    if(fopen(taskname".inp", "r")) {
        freopen(taskname".inp", "r", stdin);
        freopen(taskname".out", "w", stdout);
    }
    cin >> n >> x;
    ll res = LLONG_MAX;
    for(int i = 1 ; i <= n ; ++i){
        cin >> a[i];
        s[i] = a[i] + s[i - 1];
    }
    vector<int> delta;delta.pb(5);
    for(int i = 2 ; i <= n ; ++i){
        delta.pb(i * 2 + 1);
    }
    for(int i = 1 ; i <= n ; ++i){
        int now = n;
        ll tmp = 0;
        for(int c : delta){
            function<ll(ll , ll )> Mul = [&](ll x , ll y){
                if(llinf / y < x)return llinf;
                return x * y;
            };
            if(now > i){
                tmp += Mul((s[now] - s[now - i]) , c);
            }else tmp += Mul((s[now]) , c);
            tmp = min(tmp,llinf);
            now -= i;
            if(now <= 0)break;
        }
        res = min(res , tmp + (ll)(n + i) * x);
    }
    cout << res;
}

