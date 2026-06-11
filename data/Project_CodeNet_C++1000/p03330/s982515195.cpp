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


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    ll n,c;
    cin >> n >> c;
    vector<vector<ll>> color(c+1,vector<ll>(c+1));
    for (int z=1;z<=c;z++){
        for (int x=1;x<=c;x++){
            cin >> color[z][x];
        }
    }
    vector<vector<ll>> grid(n,vector<ll>(n));
    for (int z=0;z<n;z++){
        for (int x=0;x<n;x++){
            cin >> grid[z][x];
        }
    }
    vector<vector<ll>> arr(c+1,vector<ll>(3));
    for (int col = 1;col<=c;col++){
        for (int z=0;z<n;z++){
            for (int x=0;x<n;x++){
                arr[col][(z+x+2)%3] += color[grid[z][x]][col];
            }
        }
    }
    ll ans = LLONG_MAX;
    for (int z=1;z<=c;z++){
        for (int x=z+1;x<=c;x++){
            for (int y=x+1;y<=c;y++){
                ans = min(ans,arr[z][0]+arr[x][1]+arr[y][2]);
                ans = min(ans,arr[z][0]+arr[x][2]+arr[y][1]);
                ans = min(ans,arr[z][1]+arr[x][0]+arr[y][2]);
                ans = min(ans,arr[z][1]+arr[x][2]+arr[y][0]);
                ans = min(ans,arr[z][2]+arr[x][0]+arr[y][1]);
                ans = min(ans,arr[z][2]+arr[x][1]+arr[y][0]);
            }
        }
    }
    cout << ans << endl;
} 