#include <bits/stdc++.h>
 
using namespace std;
 
#define mp make_pair
#define endl '\n'
using ll=long long;
 
const int INF=1e9+5;
const ll lim=(ll)3e16;
const int N=3e3+5;
const int mod=1e9+7;
const ll oo=1e18+5;
 
int n;
vector<ll> dp;
vector<ll> pre;

void go(int id,const vector<int>& tmp,ll score,int mask,int add_mem){
	if(id==(int)tmp.size()){
		dp[mask]=max(dp[mask],score+pre[add_mem]);
		return;
	}
	go(id+1,tmp,score,mask,add_mem);
	go(id+1,tmp,score,mask^(1<<tmp[id]),add_mem^(1<<tmp[id]));
}

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
	cin>>n;
	vector<vector<ll>> in(n,vector<ll>(n));
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cin>>in[i][j];
		}
	}
	pre.resize(1<<n);
	for(int mask=0;mask<(1<<n);++mask){
		for(int i=0;i<n;++i){
			if(mask&(1<<i)){
				for(int j=i+1;j<n;++j){
					if(mask&(1<<j)){
						pre[mask]+=in[i][j];
					}
				}
			}
		}
	}
	// dp[mask] the total score if we grouped rabbits from mask already
	dp.resize(1<<n,-oo);
	dp[0]=0;
	for(int mask=0;mask<(1<<n);++mask){
		vector<int> tmp;
		for(int i=0;i<n;++i){
			if(!(mask&(1<<i))){
				tmp.push_back(i);
			}
		}
		go(0,tmp,dp[mask],mask,0);
	}
	cout<<dp[(1<<n)-1];
	return 0;
}

