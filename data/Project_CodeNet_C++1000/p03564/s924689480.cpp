#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int main(){
    fast;
	ll n,k,ans=0,val=1;
	cin>>n>>k;
	if(val+k<val*2){
	while(val+k<val*2&&ans<n)
		val+=k,ans++;
	while(ans<n)
		val*=2,ans++;
	}
	else{
	while(val*2<val+k&&ans<n)
		val*=2,ans++;
	while(ans<n)
		val+=k,ans++;
	}
    cout<<val;
    return 0;
}
