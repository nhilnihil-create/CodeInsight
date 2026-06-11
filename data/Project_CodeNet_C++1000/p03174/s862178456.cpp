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
const int mod = 1e9+7;
const ll MAX = 1000000000000000000;
typedef pair<int,ll> pii;
typedef pair<ll,int> pi;
typedef tuple<long long,int> tp;
typedef tuple<int,int,long long> tu;
typedef multimap<pii , int> mpp;
typedef priority_queue< tp , vector<tp>, greater<tp>>  minheap;
typedef priority_queue<pii , vector<pii>> maxheap;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>  new_data_set;
const int maxi = 10000001;

void add(int &m, int x){
	m += x;
	m %= mod;
}

int main()
{
	FASTIO;
	
	int n;
	cin >> n;
	vector<vector<int>> arr(n, vector<int>(n));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> arr[i][j];
		}
	}
	vector<int> dp((1<<n));
	dp[0]=1;
	for(int mask=0;mask<(1<<n)-1;mask++){
		int a = __builtin_popcount(mask);
		for(int b=0;b<n;b++){
			if(arr[a][b] && !(mask & (1<<b))){
				int m = mask ^(1<<b);
				add(dp[m],dp[mask]);
			}
		}
	}
	
	cout << dp[(1<<n)-1] << "\n";
	return 0;
}
