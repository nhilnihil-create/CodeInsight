#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	string s;
	cin>>s;
	string t;
	cin>>t;
	int N_t=t.size();
	int N_s=s.size();
	if(N_t>N_s)
	{
		cout<<"UNRESTORABLE"<<endl;
		return 0;
	}
	bool is_match=false;
	for(int i=N_s-1;i>=N_t-1;i--)
	{
		bool flag=true;
		for(int j=0;j<N_t;j++)
		{
			if(!(s[i-j]=='?'||s[i-j]==t[N_t-1-j]))
			{
				flag=false;
				break;	
			}
		}
		if(flag)
		{
			is_match=true;
			for(int j=0;j<N_t;j++)
			{
				s[i-j]=t[N_t-1-j];
			}
			break;
		}
	}
	if(!is_match)
	{
		cout<<"UNRESTORABLE"<<endl;
	}
	else
	{
		rep(i,N_s)
		{
			if(s[i]=='?') s[i]='a';
		}
		cout<<s<<endl;
	}
	return 0;
}
