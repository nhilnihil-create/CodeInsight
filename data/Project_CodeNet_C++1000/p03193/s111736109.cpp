#include "bits/stdc++.h"
using namespace std;

#define ll long long
ll n,h,w,a,b,cnt=0;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>h>>w;
	for(ll i=0;i<n;i++){
		cin>>a>>b;
		if(a>=h && b>=w)
			cnt++;
	}
	cout<<cnt;
	return 0;
}