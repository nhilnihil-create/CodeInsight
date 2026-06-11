	#include<bits/stdc++.h>
	using namespace std;
	typedef long long ll;
	#define f(i,n) for(ll i=0;i<n;i++)
	#define pb push_back
	int mod=1e9+7;
	int gcd (int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
	ll fast(ll a,ll n){
		a%=mod;
		ll res=1;
		while(n>0){
			if(n&1)res=res*a%mod;
			a=a*a%mod;
			n>>=1;
		}
		return res;
	}
	int func(int a){
		int sum=0;
		while(a){
			sum+=a%10;
			a/=10;
		}
		return sum;
	}
	// vector<int> v;
const int maxn=22;

  int dp[(1<<21)][22];
  // int res=0;
  // int mod=1e9+7;
  int dfs(vector<vector<int>>&a,long long vis,long long j ){
    int n=a.size();
      if(j==n){return 1;}
      // long long res=0;
      if(dp[vis][j]!=-1)return dp[vis][j]%mod;
      dp[vis][j]=0;
      for(int i=0;i<n;i++){
        if(!(vis&(1<<i))&&(a[i][j]==1)){
          // cout<<"asas"<<i<<" asgva"<<vis<<endl;
          long long temp=vis|(1<<i);
          dp[vis][j]+=dfs(a,temp,j+1)%mod;
          dp[vis][j]%=mod;

        }

        // if(!vis[i]&&a[i][j]==1){
        //   vis[i]=true;
        //   dfs(a,vis,j+1);
        //   vis[i]=false;
        // }
      }
      return dp[vis][j]%mod;


  }
	int main(){
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
    memset(dp,-1,sizeof dp);
    int n;
    cin>>n;
    vector<vector<int>>a(n,vector<int>(n));
    f(i,n){
      f(j,n) cin>>a[i][j];
    }
    // vector<bool>vis(n,false);
    // long long vis=1;
    long long res=0;
  for(int i=0;i<n;i++){
    if(a[i][0]==1){
      // cout<<i<<endl;
      res+=dfs(a,1<<i,1);}
    res%=mod;
  }
   cout<<res;
		return 0;
	}

