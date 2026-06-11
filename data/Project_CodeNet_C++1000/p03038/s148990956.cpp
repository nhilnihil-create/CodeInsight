#include<iostream>
#include<unordered_map>
#include<bitset>
#include<math.h>
#include<vector>
#include<set>
#include<algorithm>
#include<ctype.h>
#include<unordered_set>
#include<string>
#include<iomanip>
#include<queue>
#include<limits>
#include<map>
#include<stack>
#include<iterator>
#include<cstring>
#include<deque>
#include<chrono>
using namespace std;
#define pi 3.141592653589793238


#define MOD 1000000007
#define INF 999999999999999999 
#define pb push_back
#define ff first
#define ss second
#define mt make_tuple
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define f0 get<0>
#define f1 get<1>
#define f2 get<2>
typedef vector<ll> vi;
typedef vector<vi> vvi;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fast;
    ll T = 1, i, j;
    
    
    //cin >> T;
    while (T--) {
        ll n, m;
        cin >> n >> m;
        vector<ll> v(n);
        for(i = 0; i < n; i++){
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        vector<pair<ll,ll>> a(m);
        for(i = 0; i < m; i++){
            cin >> a[i].ss >> a[i].ff;
        }
        sort(a.begin(), a.end());
        ll cnt = 0;
        for(i = m - 1; i >= 0; i--){
            while(a[i].ss--){
                if(v[cnt] >= a[i].ff){
                    cnt = n;
                    break;
                }
                v[cnt++] = a[i].ff;
                if(cnt == n){
                    break;
                }
            }
            if(cnt == n){
                break;
            }
        }
        ll ans = 0;
        for(i = 0; i < n; i++){
            ans += v[i];
        }
        cout << ans;
    }

    return 0;
}
