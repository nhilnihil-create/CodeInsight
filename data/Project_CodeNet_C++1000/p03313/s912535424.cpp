#include<bits/stdc++.h>
 
using namespace std;
/*
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
*/
typedef long long ll ;
const ll mk = 200055;
const ll logn  = 29;
const ll mod = 1e9 + 7;
 
#define endl             "\n"
#define IOS              ios::sync_with_stdio(0); cin.tie(0);
#define fi               first
#define se               second
#define pii              pair<ll,ll>
#define mp               make_pair
#define pq               priority_queue<int, std::vector<int>, std::greater<int> >
#define rep(i, n)        for(int i = 0 ; i < n ; i++)
#define repf(i , n )     for(int i = 1; i <= n ; i++)
#define pb               push_back

int dp[1 << 20] ;
int a[1 << 20] , n ;

void init() {
	cin >> n ; 
	for(int i = 0 ; i < (1 << n) ; i++) cin >> a[i];
	for(int i = 1 ; i < (1 << n) ; i++) {
		int x = 0 , y = 0; 
		for(int sub_mask = i ; ; sub_mask = (sub_mask - 1) & i) 
		{
			if(a[sub_mask] > y) x = y, y = a[sub_mask];
			else if(a[sub_mask] > x) x = a[sub_mask];
			if(!sub_mask)  break;
		}
		//cout << x << ' ' << y << ' ';
		dp[i] = max(dp[i - 1] , x + y);
		cout << dp[i] << endl; 
	}
}

signed main() {
    init();
}