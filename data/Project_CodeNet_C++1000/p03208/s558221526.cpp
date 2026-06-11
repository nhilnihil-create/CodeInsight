#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
	long long n,k,h[100005],ans=10000000000;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>h[i];
	}
	sort(h,h+n);
	for(int i=0;i<n-k+1;i++){
		if(h[i+k-1]-h[i]<ans)
			ans=h[i+k-1]-h[i];
	}
	cout<<ans<<endl;
    return(0);
}