#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
typedef vector<pii> vii;
typedef vector<pll> vll;
#define fi first
#define se second
#define pi 3.141592653589793
#define mod 1e9 + 7
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.begin(), v.end(), greater<ll>()
#define tc int t;cin>>t;while(t--)
#define pqmax priority_queue<int>
#define pqmin priority_queue<int,vi,greater<int>>
#define fast_io ios_base::sync_with_stdio(0), cin.tie(NULL)
#define tc_g int tt;cin>>tt;for(int ti=1;ti<=tt;ti++)
#define case_g "Case #"<<ti<<": "
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, int, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_map;
using namespace std;
ll xornum(ll a) {
    if(a < 0)
        return 0;
    if(a % 4 == 0)
        return a;
    else if(a % 4 == 1)
        return 1;
    else if(a % 4 == 2)
        return a + 1;
    return 0;
}
int main() {
    ll a, b;
    cin >> a >> b;
    cout << (xornum(b)^xornum(a - 1));
}
