#include<bits/stdc++.h>
using namespace std;
int n,k;
int arr[105];
int dp[100005][2];
int f(int left,int turn){
	//cout<<left<<" "<<turn<<'\n';
	int&ret = dp[left][turn];
	if(~ret) return ret;
	ret = 0;
	if(left==0) return ret = 0;
	for(int i=0; i<n; i++){
		if(left>=arr[i]){
			//내가 이기는 경우가 있다면 
			if(f(left-arr[i],!turn)==0) return ret = true;
		}
	}
	return ret;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(dp,-1,sizeof(dp));
	cin>>n>>k;
	for(int i=0; i<n; i++) cin>>arr[i];
	if(f(k,0)) cout<<"First";
	else cout<<"Second";
}