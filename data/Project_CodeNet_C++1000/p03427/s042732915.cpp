#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF 1000000000000000007
#define pb emplace_back 
#define mx 1e9+2
#define all(s) s.begin(),s.end()
typedef vector<int> vi;
ll ans=0;
int gh[20];
ll dp[20][164][2];
ll getsum(int idx,int n,ll sum,bool flag){
		ans=max(sum,ans);
	if(idx>n)return sum;
	if(dp[idx][sum][flag]!=-1)return dp[idx][sum][flag];
	int limit=9;
	if(!flag)limit=gh[idx];
	ll res=0;
	for(int i=0;i<=limit;i++){
		if(i<limit||flag){
			res+=getsum(idx+1,n,sum+i,true);
		}
		else{
			res+=getsum(idx+1,n,sum+i,false);
		}
	}
	return dp[idx][sum][flag]=res;
}
void solve(){
	string b;
	cin>>b;
	for(int i=0;i<b.size();i++){
		gh[i+1]=b[i]-'0';
	}
	memset(dp,-1,sizeof dp);
  ll r=getsum(1,b.size(),0,0);
   cout<<ans<<"\n";
}

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
   int t=1;
  // cin>>t;
     while(t--){
     	solve();
	 }
     return 0;
}