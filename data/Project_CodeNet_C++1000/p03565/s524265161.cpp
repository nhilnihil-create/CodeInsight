#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007


void solve()
{
	string s,t;
	cin>>s>>t;
	ll a=s.size();
	ll b=t.size();
	if(a<b)
	{
		cout<<"UNRESTORABLE";
		return;
	}
	string ans(a,'z');
	// cout<<ans;
	ll c=0,f=0;
	for(ll i=0;i<a-b+1;i++)
	{
		c=0;
		for(ll j=i;j<i+b;j++)
			if(s[j]!=t[j-i] && s[j]!='?')
			{
				c=1;
				break;
			}
		if(c==0)
		{
			string ans1=s;
			for(ll j=i;j<i+b;j++) 
				ans1[j]=t[j-i];
			
			
			for(ll j=0;j<a;j++)
				if(ans1[j]=='?')
					ans1[j]='a';
				
			ans=min(ans,ans1);
			f=1;
		}
	}
	if(f==0)
		cout<<"UNRESTORABLE";
	else
		cout<<ans;
    return;
}

int main()
{
        fast;
        ll q;
        q=1;
        // cin>>q;
        while(q--)
        	solve();
        
        return 0;
}
