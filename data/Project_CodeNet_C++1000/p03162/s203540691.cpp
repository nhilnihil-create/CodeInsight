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

lld dp[100005][3]={0};

struct activity{
	lld a,b,c;
};

lld findMaxHappiness(vector<activity> vac,lld n){
     dp[0][0]=vac[0].a;
     dp[0][1]=vac[0].b;
     dp[0][2]=vac[0].c;
     for(lld i=1;i<n;++i){
         dp[i][0]=vac[i].a+max(dp[i-1][1],dp[i-1][2]);
         dp[i][1]=vac[i].b+max(dp[i-1][0],dp[i-1][2]);
         dp[i][2]=vac[i].c+max(dp[i-1][0],dp[i-1][1]);
     }
     return max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
}

int main(){

	#ifndef ONLINE_JUDGE 
 	freopen("input.txt","r",stdin);
 	freopen("output.txt","w",stdout);
 	#endif
 	lld n;
 	cin>>n;
 	vector<activity> vac(n);
 	for(lld i=0;i<n;++i){
 		cin>>vac[i].a;
 		cin>>vac[i].b;
 		cin>>vac[i].c;
 	}cout<<findMaxHappiness(vac,n)<<endl;
}