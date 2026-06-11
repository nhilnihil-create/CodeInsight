#include<bits/stdc++.h>
using namespace std;
int n,ans=0,cnt[2][2];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string s;cin>>s;
		for(int j=0;j+1<(int)s.size();j++) if(s[j]=='A'&&s[j+1]=='B') ans++;
		cnt[s[0]=='B'][s[s.size()-1]=='A']++;
	}
	if(cnt[1][1])
	{
		ans+=cnt[1][1]-1;
		if(cnt[1][0]) cnt[1][0]--,ans++;
		if(cnt[0][1]) cnt[0][1]--,ans++;
	}
	ans+=min(cnt[1][0],cnt[0][1]);
	cout<<ans<<endl;
}