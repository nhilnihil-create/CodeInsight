#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
 
#define ll              long long int
#define vll             vector<ll>
#define vs              vector <string>                                    
#define mll             map<ll,ll>
#define pll             pair<ll, ll>
#define vpll            vector < pair<ll,ll> >
#define itr             vll::iterator
#define all(c)          c.begin(),c.end()
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define ps(x,y)         fixed<<setprecision(y)<<x
#define pb              push_back
#define mb              make_pair
#define ff              first
#define ss              second
#define max3(a,b,c)     max(max(a,b),c)                                    
#define min3(a,b,c)     min(min(a,b),c)  
#define mod             1000000007
#define inf             1000000000000000001
#define from(i, n)      for(__typeof(n) i = 0; i <  n; ++i)
#define fromj(i, j, n)  for(__typeof(n) i = j; i <  n; ++i)
#define printv(v)       from(i,v.size())cout<<v[i]<<" ";cout<<"\n";
#define w(x)            int x; cin>>x; while(x--)
 
using namespace std;
using namespace __gnu_pbds; 
 
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}
 
bool func(const pll &a, const pll &b){
    if(a.ss==b.ss)return a.ff<b.ff;
    return a.ss < b.ss;
}
typedef tree<int, null_type, less<int >, rb_tree_tag, 
             tree_order_statistics_node_update> pbds; 
long long solve(vector<vll>&dp,long long subset,int num,vector<vector<bool> >&compat){
	if(num == compat.size()+1){
		if(subset==0)return 1;
		else return 0;
	}
	if(dp[num][subset]!=-1)return dp[num][subset];
	long long ans=0;
    for(int k=1;k<compat.size()+1;k++){
    	if(subset&(1<<(k-1)) && compat[num-1][k-1]){
    		ans=(ans+solve(dp,subset^(1<<(k-1)),num+1,compat))%mod;
    	}
    }
    dp[num][subset]=ans;
    return ans;
}
int main(){
    c_p_c();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<vector<bool> > compat(n,vector<bool>(n,0));
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		bool temp;
    		cin>>temp;
    		compat[i][j]=temp;
    		//cout<<compat[i][j]<<" ";
    	}	
    	//cout<<"\n";
    }
    vector<vll> dp(n+1,vll(1<<n,-1));
    //memset(dp,0,sizeof(dp));
    cout<<solve(dp,(1<<n)-1,1,compat);
}    