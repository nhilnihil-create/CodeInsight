#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7,MAX = 1e5;

int main()
{
	ll n;
	cin >> n;
	string s;
	cin >> s;
	ll ss = s.size();
	ll q;cin >> q;
	for(ll ii = 0 ;ii<q;ii++)
	{
		ll k;
		cin >> k;
		ll cntd=0,ans=0,cntm=0,cnt=0;
		for(ll i = 0;i<n;i++)
		{
			if(i-k>=0&&s[i-k]=='D')
			{
				cntd--;
				cnt -= cntm;
			}
			if(i-k>=0&&s[i-k]=='M')
			{
				cntm--;
			}
			if(s[i]=='D')
			{
				cntd++;
			}
			else if(s[i]=='M')
			{
				cntm++;
				cnt+=cntd;
			}
			else if(s[i]=='C')
			{
				ans+=cnt;
			}
			
		
		}
		cout<<ans<<endl;
	}
	return 0;
}