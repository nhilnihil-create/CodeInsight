#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnt[2][214514];
int main(){
	ll n;
	string s;
	cin>>n>>s;
	if(s[0]=='#')cnt[0][0]++;
	else cnt[1][0]++;
	for(int i=1;i<n;i++){
		cnt[0][i]=cnt[0][i-1];
		cnt[1][i]=cnt[1][i-1];
		if(s[i]=='#')cnt[0][i]++;
		else cnt[1][i]++;
	}
	ll ans=cnt[1][n-1];
	for(int i=0;i<n;i++){
			ans=min(ans,cnt[0][i]+cnt[1][n-1]-cnt[1][i]);
	}
	cout<<ans;
	return 0;
}
