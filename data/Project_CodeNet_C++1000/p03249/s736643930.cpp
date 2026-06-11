#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <sstream>
#include <stack>
#include <time.h>
#include <vector>
#include <complex>
#include <map>
#include <set>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <list>
#include <utility>
#include <memory>
#include <cstring>
#include <fstream>
#include <numeric>
#include <assert.h>
#include <bitset>
#include <ios> 
#include <bits/stdc++.h>
using namespace std;
void coutno(){
	puts("-1");exit(0);
}
int n;
typedef long long ll;
map <ll,int> mp;
vector<pair<ll,int> > v;
vector<pair<int,int> > res;
ll dp[100004];
int sz[100004]; 
int main(){
	for (int i=0;i<100004;i++) sz[i]=1;
	cin>>n;
	for (int i=1;i<=n;i++){
		ll x;cin>>x;
		mp[x]=i;v.push_back(make_pair(x,i));
	}
	sort (v.rbegin(),v.rend());
	ll x=v.back().first;
	for (int i=0;i<v.size();i++){
		if (v[i].first!=x){
			pair<ll,int> q=v[i];
			if (sz[q.second]*2>=n) coutno();
			ll need=q.first-(n-2*sz[q.second]);
			if (!mp.count(need)) coutno();
			int par=mp[need];
			dp[par]+=dp[q.second]+sz[q.second]; 
			sz[par]+=sz[q.second]; 
			res.push_back(make_pair(q.second,par)); 
		}
	}
	if (dp[v.back().second]!=x)coutno();
	for (int i=0;i<n-1;i++)
		cout<<res[i].first<<" "<<res[i].second<<"\n";
}