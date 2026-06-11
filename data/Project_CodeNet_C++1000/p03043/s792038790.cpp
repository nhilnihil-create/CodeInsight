#include<bits/stdc++.h>
//#include<iostream>
 
using namespace std;
 
typedef long long ll;
 
const int N = 200005;
 
ll n,k;
int a[N];
 
ll pot[33];
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	pot[0] = 1;
	for(int i=1;i<30;i++){
		pot[i] = pot[i-1]*2;
	}
	
	cin>>n>>k;
	
	a[k] = 0;
	for(int i=k-1;i>0;i--){
		a[i] = a[i*2]+1;
	}
	
	ll sm = 0;
	for(int i=1;i<=n;i++){
		sm += pot[a[1] - a[i]];
	}
	
	long double ans = (1.0*sm)/(1.0*n)/(1.0*pot[a[1]]);
	cout<<fixed<<setprecision(12)<<ans;
	
	return 0;
}
