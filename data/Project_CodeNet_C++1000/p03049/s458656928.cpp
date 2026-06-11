#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ll n;

	cin>>n;
	ll ans=0,cnt[3]={};
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		if(s[0]=='B'){
			if(s[s.size()-1]=='A')cnt[0]++;
			else cnt[2]++;
		}else if(s[s.size()-1]=='A')cnt[1]++;
		for(int j=0;j<s.size();j++){
			if(j){
				if(s[j-1]=='A'&&s[j]=='B')ans++;
			}
		}
	}
	//cout<<ans<<endl;
	if(cnt[1]&&cnt[2]){
		ans+=cnt[0]+1;
		cnt[1]--;
		cnt[2]--;
		ans+=min(cnt[1],cnt[2]);
	}else if(cnt[1]==0&&cnt[2]==0)ans+=max(0ll,cnt[0]-1);
	else ans+=cnt[0];
	cout<<ans<<endl;
	return 0;
}
