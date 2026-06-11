#include<bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=0;i<n;i++)
#define forn2(i,a,n) for(int i=a;i<n;i++)
#define fore(i,n) for(int i=1;i<=n;i++)
#define fore2(i,a,n) for(int i=a;i<=n;i++)
#define forp(i,n) for(int i=n;i>0;i--)
#define fort(i,n) for(int i=n;i>=0;i--)
int sz,sz2;
string small="~";
string s,t,s2;
bool check()
{
	fore2(i,0,sz-sz2)
	{
		bool ok=0;
		forn(c,sz2)
		{
			if(s2[i+c]!=t[c])
				ok=1;
		}
		if(ok==0)
			return true;
	}
	return false;
}
void b()
{
	forn(c,sz)
		if(s2[c]=='?')
			s2[c]='a';
}
int main()
{
	cin>>s>>t;
	sz=s.size();sz2=t.size();
	s2=s;
	forn(i,sz)
		if(s2[i]=='?')
			s2[i]='a';
	if(check())
	{
		cout<<s2<<endl;
		return 0;
	}
	fore2(i,0,sz-sz2)
	{
		s2=s;
		forn(c,sz2)
			if(s2[c+i]=='?')
				s2[c+i]=t[c];
		b();
		if(check())
			small=min(small,s2);
	}
	if(small=="~")
	{
		cout<<"UNRESTORABLE"<<endl;
		return 0;
	}
	else
	{
		cout<<small<<endl;
		return 0;
	}
	return 0;
}