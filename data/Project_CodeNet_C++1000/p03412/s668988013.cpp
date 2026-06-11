#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back
#define INF 1e18
#define MOD 1000000007
#define N 1000005
#define BB(V) V[V.size()-2]
#define ex(V) return printf(V),0
using namespace std;
int n,a[200005],b[600005];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	for(int i=0;i<n;i++)scanf("%d",b+i);
	int ans=0;
	for(int i=28;i>=0;i--){
		ll t=0;
		sort(b,b+n);
		for(int j=0;j<2*n;j++)b[j+n]=b[j]+(2<<i);
		for(int j=0;j<n;j++){
			t+=lower_bound(b,b+3*n,(4<<i)-a[j])-lower_bound(b,b+3*n,(3<<i)-a[j]);
		}
		if(t%2)ans+=(1<<i);
		for(int j=0;j<n;j++)a[j]%=(1<<i),b[j]%=(1<<i);
	}
	printf("%d",ans);
}