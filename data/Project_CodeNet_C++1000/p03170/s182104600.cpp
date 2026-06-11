/* Author- Abhijeet Trigunait */

#include<bits/stdc++.h>
#define lld long long int
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define mod 1e9+7
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define gcd(x,y) __gcd(x,y)
#define endl '\n'

using namespace std;


string solve(vector<lld> vec,lld k){
	bool dp[k+1];
	memset(dp,0,sizeof(dp));
	for(lld i=1;i<=k;++i){
		for(auto x:vec){
			if(x>i)continue;
			if(dp[i-x]==0){
				dp[i]=1;
			}
		}
	}return dp[k] ? "First" : "Second";

}

int main(){

	#ifndef ONLINE_JUDGE 
 	freopen("input.txt","r",stdin);
 	freopen("output.txt","w",stdout);
 	#endif
 	lld n,k;
 	cin>>n>>k;
    vector<lld> vec(n);
    for(lld i=0;i<n;++i)cin>>vec[i];
    cout<<solve(vec,k)<<endl;
}