#include "bits/stdc++.h"
using namespace std;

#define ff first
#define ss second
#define pb push_back
#define int long long

bool comp(int a,int b){
return a>b ;	
}


bool foo(int arr[],int n,int k){
	
	if(n==0 || k==0)
	return 0;
	
	for(int i=0;i<n;i++){
		if(k>=arr[i]){	
			bool state=foo(arr,n,k-arr[i]);
			if(!state)
				return 1;
		}
	}
	return 0;
}

signed main(){

//int mod=1000000007;

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
#else
// online submission
#endif

int n,k;
cin >> n >> k;

int arr[n];
for(int i=0;i<n;i++)
cin >> arr[i] ;


int dp[k+1]={0};

for(int i=0;i<=k;i++){
	for(int j=0;j<n;j++){
		
		if(i>=arr[j] && dp[i-arr[j]]==0 ){
				dp[i]=1;
				break;
		}
	}
}

bool ans=dp[k];
if(ans)
cout<<"First";
else cout<<"Second";

	return 0;
    
}


