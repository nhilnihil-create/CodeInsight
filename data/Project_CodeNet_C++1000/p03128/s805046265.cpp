#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#define REP(i,n) for(int i=0;i<(n);++i)
#define ALL(v)   (v).begin(),(v).end()
using namespace std;
typedef vector<int> vi;

//dp.
int main(){
	const int num[]={0,2,5,5,4,5,6,3,7,6};//数字iにnum[i]本必要.
	
	int n,m;
	cin>>n>>m;
	
	vi a(m);
	REP(i,m) cin>>a[i];
	
	vi dp(n+1,-1);//i本でdp[i]桁作る.
	dp[0]=0;//point.
	REP(i,n){
		if(dp[i]==-1) continue;
		REP(j,m){
			if(i+num[a[j]]<=n) dp[i+num[a[j]]]=max(dp[i+num[a[j]]],dp[i]+1);
		}
	}
	
	string ans="";//point.
	sort(ALL(a),greater<int>());//point.
	while(n>0){
		REP(i,m){
			if(n-num[a[i]]>=0){
				if(dp[n]==dp[n-num[a[i]]]+1){
					ans+='0'+a[i];
					n-=num[a[i]];
					break;//REP(i).
				}
			}
		}
	}
	
	cout<<ans<<endl;
}
