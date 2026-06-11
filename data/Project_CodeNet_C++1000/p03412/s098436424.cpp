#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ll,ii>

int n;
int arr[200005];
int brr[200005];

int prec[30];

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	
	for (int x=0;x<30;x++) prec[x]=(1<<(x+1))-1;
	
	cin>>n;
	for (int x=0;x<n;x++) cin>>arr[x];
	for (int x=0;x<n;x++) cin>>brr[x];
	
	int ans=0;
	for (int b=28;~b;b--){
		int nums=0;
		for (int x=0;x<n;x++) brr[x]&=prec[b],arr[x]&=prec[b];
		sort(brr,brr+n);
		
		for (int x=0;x<n;x++){
			nums+=lower_bound(brr,brr+n,2*(1<<b)-arr[x])-lower_bound(brr,brr+n,1*(1<<b)-arr[x]);
			nums+=lower_bound(brr,brr+n,4*(1<<b)-arr[x])-lower_bound(brr,brr+n,3*(1<<b)-arr[x]);
		}
		if (nums&1) ans+=(1<<b);
	}
	
	cout<<ans;
}