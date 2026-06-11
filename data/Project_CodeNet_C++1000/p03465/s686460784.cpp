#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define N 500009
#define inf 999999999999
#define pb push_back
#define M (L+R)/2
using namespace std;

ll n,a[N],ans=inf,sum,ind;
bitset <4000009> dp;
int main(){
	
	ios::sync_with_stdio(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	dp[0]=1;

	for(int i=1;i<=n;i++){
		dp=dp|(dp<<a[i]);
	}
	
	for(int i=4000000;i>=sum/2;i--){
		if(dp[i]){
			if(abs(sum-2*i)<ans)ans=abs(sum-2*i),ind=i;
		}
	}
	cout<<ind<<endl;
	return 0;
}