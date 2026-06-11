#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
#define rep(i,b,e) for(ll i=b;i<e;i++)

vector <long long> pre;
vector <vector<long long>> a;
vector <long long> dp;

void solve(int i,const vector<int>& not_taken,ll score_so_far,int mask,int group){
	if(i==(int)not_taken.size()){
		dp[mask]=max(dp[mask],score_so_far+pre[group]);
		return;
	}

	solve(i+1,not_taken,score_so_far,mask,group);
	solve(i+1,not_taken,score_so_far,mask^(1<<not_taken[i]),group^(1<<not_taken[i]));
}

const ll INF = 1e18l+5;
int main(){
	int n;
  	cin>>n;
	a.resize(n,vector<long long>(n));
	pre.resize(1<<n,0);
	dp.resize(1<<n,-INF);

	rep(i,0,n)
		rep(j,0,n)
			cin>>a[i][j];

	rep(mask,0,(1<<n)){
		rep(i,0,n){
			if(mask&(1<<i)){
				rep(j,i+1,n){
                  if(mask&(1<<j))
					pre[mask]+=a[i][j];
				}
			}
		}
	}
	//calculating value of each group
	//O(2ⁿ*n²)
	dp[0]=0;
	rep(mask,0,(1<<n)){
		vector<int> not_taken;
		rep(i,0,n){
			if(!(mask&(1<<i)))
				not_taken.push_back(i);
		}
		solve(0,not_taken,dp[mask],mask,0);
      	//cout<<dp[mask]<<endl;
	}
	cout<<dp[(1<<n)-1]<<endl;
}
