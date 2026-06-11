#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
typedef long long ll;
using namespace __gnu_pbds;
using namespace std;
typedef pair<ll, ll> pll;


ll n;
ll a[100005];
ll minm = 1e16;
ll maxm = 0;
ll b[100005];
ll s[100005];
typedef tree<
pll,
null_type,
less<pll>,
rb_tree_tag,
tree_order_statistics_node_update>
box;
const ll inf= 1e16;
ll M;
bool check(ll x)
{
        for(ll i=1;i<=n;i++) {
                if(a[i] <= x) {
                        b[i] = 1;
                }else b[i] = -1;
        }
        for(ll i=1;i<=n;i++) {
                s[i] = s[i-1] + b[i];
        }
        ll ans = 0;
        box tree;
        tree.insert(make_pair(0 , 0));
        for(ll i=1;i<=n;i++) {

                ll id = tree.order_of_key(make_pair(s[i] , -1));
                /*if(x == 20) {
                        cout << id << " " << endl;
                }*/
                ans += id;
                //if(id != tree.size() && tree.find_by_order(id) == )
                tree.insert(make_pair(s[i] , i));
        }
        /*if(x==20) {
                cout << ans << " " << (M/2) + 1 << endl;
        }*/
        return (ans >= (M/2)+1);
}
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
        cin >> n;
        M = (n*(n+1))/2;
        for(ll i=1;i<=n;i++) {
                cin >> a[i];
                maxm = max(maxm , a[i]);
                minm = min(minm, a[i]);
        }
        ll lo = minm - 1;
        ll hi = maxm;
        while(hi > lo) {

                ll mid = lo + (hi - lo ) /2;
                if(check(mid)) {
                        hi = mid;
                }else lo = mid +1;
        }
        cout << lo << endl;
        return 0;
}
