#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll cnt[200010];
int main() {
	ll n;
	cin>>n;
	string s;
	cin>>s;
	for(ll i=n-1;i>=0;i--){
		if(s[i]=='.'){
			cnt[i]=1;
		}
	}
	for(ll i=n-2;i>=0;i--){
		cnt[i]=cnt[i]+cnt[i+1];
	}
	ll ans=cnt[0];
	ll ans1=0;
	for(ll i=0;i<n;i++){
		if(s[i]=='#'){
			ans1++;
		}
		ans=min(ans,ans1+cnt[i+1]);
	}
	cout <<ans;
	// your code goes here
	return 0;
}