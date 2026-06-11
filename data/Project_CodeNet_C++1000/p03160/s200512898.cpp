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

lld dp[100010]={0};

namespace MinCost{
	lld getMin(lld *arr,lld n){
        dp[0]=arr[0];
        dp[1]=abs(arr[1]-arr[0]);
        dp[2]=abs(arr[2]-arr[0]);
        for(lld i=3;i<n;++i){
        	lld op1=dp[i-1]+abs(arr[i]-arr[i-1]);
        	lld op2=dp[i-2]+abs(arr[i]-arr[i-2]);
        	dp[i]=min(op1,op2);
        }
        return dp[n-1];
	}
}

int main(){

 	lld n;
 	cin>>n;
 	lld arr[n];
 	for(lld i=0;i<n;++i)cin>>arr[i];
 	cout<<MinCost::getMin(arr,n);
}