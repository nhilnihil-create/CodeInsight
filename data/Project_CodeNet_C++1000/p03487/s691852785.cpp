#include<bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
#define sz(a) a.size()
#define re return 
#define MP make_pair
#define pb push_back
#define pii pair<int,int>
#define se second
#define fi first
using namespace std;
int n;
map<int,int> mp;
int ans;
signed main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	while(n--){
		int a;
		cin>>a;
		mp[a]++;
	}
	for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
		if((it->se)<(it->fi)) ans+=it->se;
		else ans+=(it->se)-(it->fi);
	}
	cout<<ans;
	re 0;
}