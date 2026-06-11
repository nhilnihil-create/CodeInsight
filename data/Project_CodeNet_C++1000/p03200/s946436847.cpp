#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fast ios::sync_with_stdio(false); cin.tie(NULL);
#define loop(n) for(int i=0; i<n; i++)
#define rep(i,start,n) for(int i=start; i<n; i++)

void solve(){
	string s;cin>>s;

	int n = s.length();

	int st=0,ed=n-1;

	while(s[st]!='B' && st<n)st++;
	while(s[ed]!='W' && ed>=0)ed--;

	int ans = 0;
	int cnt = 0;

	if(st>=ed  || st>=n || ed<0){
		cout<<ans<<endl;
		return;
	}

	for(int i=ed;i>=st;i--){
		if(s[i]=='W')cnt++;
		else ans+=cnt;
	}
	cout<<ans<<endl;
	
}
	
signed main(){
    fast;    
    // int t;cin>>t;while(t--)
    solve();    
    return 0;
}
