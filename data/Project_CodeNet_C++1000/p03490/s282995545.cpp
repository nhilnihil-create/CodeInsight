
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define endl "\n"
#define se second
#define ls( s) (s&(-s))
#define ll long long
#define inf 0x3f3f3f3f
const ll N = 500030;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
const ll mod =    998244353;


int main()
{
	ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
string s;
ll x1,y1;
cin>>s>>x1>>y1;
int n=s.size();
bool Bool=false;
if(s[0]=='T')
Bool=true;
set<ll> s1,s2;
int y=0;
int x=0;
while(x<n)
{

	if(s[x]=='T')
	{

	y^=1;
	x++;}
	else
	{
		ll cnt=0;
		while(x<n&&s[x]!='T')
		{
			cnt++;
			x++;
		}
	//	cout<<y<<" "<<cnt<<endl;
		if(y==0)
		{
	   bool bo=false;
	    vector<ll> v;
		for(auto it=s1.begin();it!=s1.end();it++)
		{

			v.push_back(*it+cnt);

			v.push_back(*it-cnt);
		  bo=true;
		}
		set<ll> sett;
		for(int i=0;i<v.size();i++)
		{
		sett.insert(v[i]);

		}
		s1=sett;
		if(!bo)
		{
		 if(Bool )
		 s1.insert(-cnt);
		s1.insert(cnt);}
	}
	else
	{
		bool bo=false;
			vector<ll> v;
		for(auto it=s2.begin();it!=s2.end();it++)
		{
			bo=true;

			v.push_back(*it+cnt);
			v.push_back(*it-cnt);
		}
		set<ll> sett;
		for(int i=0;i<v.size();i++)
		sett.insert(v[i]);
		s2=sett;
		if(!bo)
		{
			s2.insert(cnt);
			s2.insert(-cnt);
		}

	}
}
}
bool c=false; bool d=false;
if(s1.find(x1)!=s1.end()||(s1.size()==0&&x1==0))
c=true;
if(s2.find(y1)!=s2.end()||(s2.size()==0&&y1==0))
d=true;
if(c&&d)
cout<<"Yes";
else
cout<<"No";

}
