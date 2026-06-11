#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 

int main() {
	ll n,k,a[52],ans=-INF;;
	cin>>n>>k;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}		
	for(ll i=0;i<=k;i++){
		//i はとるかず
		for(ll l=0;l<=min(i,n);l++){
			ll r=min(i,n)-l;
			vector<ll>cnt;
			for(ll j=0;j<l;j++){
				cnt.push_back(a[j]);
			}
			for(ll j=0;j<r;j++){
				cnt.push_back(a[n-1-j]);
			}

			sort(cnt.begin(),cnt.end());
			reverse(cnt.begin(),cnt.end());
			for(ll j=0;j<k-i;j++){
				if(cnt.size()==0){
					continue;
				}
				if(cnt[cnt.size()-1]<0){
					cnt.pop_back();
				}
			}
			ll cnt2=0;
			for(ll j=0;j<cnt.size();j++){
				cnt2+=cnt[j];
			}
			ans=max(ans,cnt2);
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}