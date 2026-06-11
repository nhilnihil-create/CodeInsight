#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	ll n;
	cin>>n;
	ll ar[n+1];
	ar[0]=2,ar[1]=1;
	for(int i=2;i<=n;++i){
		ar[i]=ar[i-1]+ar[i-2];
	}
	cout<<ar[n];
	return 0;
}
