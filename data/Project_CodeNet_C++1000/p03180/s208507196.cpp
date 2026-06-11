#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const ll inf=1e18;
vector<ll>dp;
vector<ll>pre;

void rec(int i,vector<int>&not_taken,ll score_so_far,int mask,int group){
	if(i==(int)not_taken.size()){
		dp[mask]=max(dp[mask],score_so_far+pre[group]);
		return;
	}
	rec(i+1,not_taken,score_so_far,mask,group);
	rec(i+1,not_taken,score_so_far,mask^(1<<not_taken[i]),group^(1<<not_taken[i]));
	}
void solve(){
	int n;
	cin>>n;
	vector<vector<int>>in(n,vector<int>(n));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>in[i][j];
		}
	}
	dp.resize(1<<n,-inf);
	pre.resize(1<<n);
	for(int mask=0;mask<(1<<n);mask++){
		for(int i=0;i<n;i++){
			if(mask&(1<<i)) {
                for (int j = i + 1; j < n; j++) {
                    if (mask & (1 << j)) {
                        pre[mask] += in[i][j];
                    }
                }
            }
		}
	}
		
	dp[0]=0;
	for(int mask=0;mask<(1<<n);mask++){
		vector<int>not_taken;
		for(int i=0;i<n;i++){
			if(!(mask&(1<<i))){
				not_taken.push_back(i);
			}
		}
		rec(0,not_taken,dp[mask],mask,0);
	}
	
	cout<<dp[(1<<n)-1]<<endl;
	
	
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	//cin>>t;
	while(t--)solve();
}
