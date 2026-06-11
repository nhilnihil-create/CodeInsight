#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize ("Ofast")
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
using namespace __gnu_pbds;
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<long long,long long> ii; 	
typedef complex<long double> com;

const ll mod = 1e9+7;

struct abc{
    ll a,b,c;
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    ll n,m;
    cin >> n >> m;
    vector <abc> arr(n);
    for (int z=0;z<n;z++){
        cin >> arr[z].a >>arr[z].b >> arr[z].c;
    }  
    vector<vector<abc>> dp;
    ll ans = 0;
    for (int y=0;y<8;y++){
        ll temp = 0;
        vector <ll> wtf(n);
        for (int z=0;z<n;z++){
            wtf[z] = 0;
            if (y & 1) wtf[z] += (arr[z].a);
            else wtf[z] -= (arr[z].a);
            if (y & 2) wtf[z] += (arr[z].b);
            else wtf[z] -= (arr[z].b);
            if (y & 4) wtf[z] +=(arr[z].c);
            else wtf[z] -= (arr[z].c);
        }
        sort(wtf.rbegin(),wtf.rend());
        for (int z=0;z<m;z++){
            temp += wtf[z];
        }
        ans = max(ans,temp);
    }
    cout << ans << endl;
}
