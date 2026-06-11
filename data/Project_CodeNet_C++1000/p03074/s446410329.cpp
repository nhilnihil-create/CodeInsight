#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	s+='2';
	ll l=0,r=0,cnt=0;
	if(s[r]=='0'){
		cnt++;
		for(ll i=0;i<n;i++){
			r=i;
			if(s[i]=='1'&&s[i+1]=='0'){
				break;
			}
		}
	}
	if(cnt!=k){
	for(ll i=1;i<n;i++){
		if(s[i-1]=='1'&&s[i]=='0'){
			cnt++;
			if(cnt>k){
				break;
			}
		}
		r=i;
	}
	}
	ll ans=r-l+1;
//	cout << ans<<endl;
	for(ll i=0;i<n;i++){
		if(s[i]=='0'&&s[i+1]=='1'){
			l=i+1;
			for(ll j=r+1;j<n;j++){
				r=j;
				if(s[j]=='1'&&s[j+1]=='0'){
					break;
				}
			}
			ans=max(r-l+1,ans);
		//	if(ans==7){
		//		cout << l << r<<endl;
		//	}
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}