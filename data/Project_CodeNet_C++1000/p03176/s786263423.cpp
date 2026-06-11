#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<cmath>
#include<queue>
#include<unordered_map>
#include<map>
#include<stack>
#include<bits/stdc++.h>
#include<string.h>
#include <ext/pb_ds/assoc_container.hpp>
#define FASTIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define f first
#define s second
#define respr(fir,sec) for(int i=0;i<=fir;i++){for(int j=0;j<=sec;j++){cout << res[i][j] << " ";}cout << "\n";}
#define pb push_back
//#define INF (1LL<<31)
using namespace std;
using namespace __gnu_pbds;
const int mod = 1000000007;
const ll MAX = 1000000000000000000;
typedef pair<int,ll> pii;
typedef pair<ll,int> pi;
typedef tuple<long long,int> tp;
typedef tuple<int,int,long long> tu;
typedef multimap<pii , int> mpp;
typedef priority_queue< tp , vector<tp>, greater<tp>>  minheap;
typedef priority_queue<pii , vector<pii>> maxheap;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>  new_data_set;
 


int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	vector<int> cost(n);
	for(int i=0;i<n;i++)
		cin >> arr[i];
	for(int i=0;i<n;i++)
		cin >> cost[i];
	vector<ll> res(n+1);
	
	ll base=1;
	while(base <=(ll)n)
		base *= 2;
	vector<ll> tree(2*base);
	
	for(int i=0;i<n;i++){
		ll stop = base + arr[i];
		ll best=0;
		while(stop>1){
			if(stop%2==1){
				best = max(best, tree[stop-1]);
			}
			stop /= 2;
		}
		
		res[arr[i]] = best+cost[i];
		
		for(ll base1=base+arr[i]; base1>=1;base1/=2)
			tree[base1] = max(tree[base1], res[arr[i]]);
	}
	ll ans=0;
	for(int i=0;i<=n;i++)
		ans= max(ans,res[i]);
	cout << ans << "\n";
	return 0;
}
