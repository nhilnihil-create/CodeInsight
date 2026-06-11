#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 

ll n,a[26],ans;
void dep(ll now,ll cnt){
	if(cnt==0){
		return;
	}
	cnt%=inf;
	if(now==26){
		ans+=cnt;
		ans%=inf;
		return ;
	}
	dep(now+1,cnt*a[now]);
	dep(now+1,cnt);
}
int main() {
	cin>>n;
	string s;
	cin>>s;
	for(ll i=0;i<n;i++){
		ll now=s[i]-'a';
		a[now]++;
	}
	dep(0,1);
	cout <<ans-1;
	// your code goes here
	return 0;
}