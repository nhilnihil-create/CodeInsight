//
//  Competitive Programming
//  Don't Copy Be Original - Ehsaan Rahman
//  Copyright © 2020 Ehsaan Rahman. All rights reserved.
//
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<bitset>
#include<cstring>
#include<stack>
#include<queue>
#include<set>
#include<chrono>
#include<list>
#include<climits>
#include<iomanip>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// #define PBDS tree<long long int,null_type,less<long long int>, rb_tree_tag,tree_order_statistics_node_update>
// using namespace __gnu_pbds;
#define arrsize 200001
#define dpsize 1001
#define w(t) while(t--)
#define PP pair<ll,ll>
#define INF 1999999996000000010
#define ll long long int
#define takeINP(arr,n) for(long long int i=0;i<n;i++) cin>>arr[i];
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define mem(arr) memset(arr,0,sizeof(arr));
#define MOD 1000000007
#define pp(a,b) make_pair(a,b)
#define print(arr,s,e) f(i,s,e) cout<<arr[i]<<" "; cout<<endl;
#define PP pair<ll,ll>
#define all(v) v.begin(),v.end()
#define ff first
#define ss second
#define vll vector<ll>
#define triplet pair<ll,pair<ll,ll> >
#define MITR(a,b) map<a,b>::reverse_iterator 
using namespace std;
using namespace chrono;

///Author - Ehsaan Rahman - Don't Copy Be Original
///---------------Functions---------------------///
ll advceil(ll num,ll den){return (num%den==0?num/den:num/den+1);}
ll lstbt(ll val){ ll msk = val&(val-1); return log2(val^msk);}
///---------x------------x----------x-----------///
map<ll,vector<ll> > edges;
ll color[arrsize]={};
ll dp[arrsize][3]={};
///1 white //2 black
ll dfs(ll src,ll par,ll parcolor){
	if(dp[src][parcolor]!=-1) return dp[src][parcolor];

	ll cnt1 = 1;
	for(auto itr : edges[src]){
		if(itr==par) continue;
		cnt1 = (cnt1%MOD*dfs(itr,src,1)%MOD)%MOD;
	}
	ll cnt2 = 1;
	if(parcolor!=2){
		for(auto itr : edges[src]){
			if(itr==par) continue;
			cnt2 = (cnt2%MOD*dfs(itr,src,2)%MOD)%MOD;
		}
    }
    else cnt2 = 0;

    return dp[src][parcolor] = (cnt1+cnt2)%MOD;
}

void solve(){
	ll n; cin>>n;
	f(i,0,n-1){
		ll x,y; cin>>x>>y;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	memset(dp,-1,sizeof(dp));
	cout<<dfs(1,0,-1)<<endl;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r" ,stdin);
		freopen("output.txt", "w" ,stdout);
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    auto start1 = high_resolution_clock::now();
    solve();
    auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
    #ifndef ONLINE_JUDGE
		cerr << "Time: " << duration.count() / 1000.0 << endl;
	    cout<<duration.count()/1000.0<<endl;
    #endif
}