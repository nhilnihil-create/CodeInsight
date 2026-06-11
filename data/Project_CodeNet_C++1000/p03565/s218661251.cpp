#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef map<ll,ll>::iterator itll;
typedef long double ld;
typedef map<ll,ll> mapll;

#define con continue
#define pb push_back
#define fi first
#define se second
#define fr front()
#define INF 1000000000000000000
#define all(vl) vl.begin(),vl.end()
#define m_p make_pair 
#define sz(a) sizeof(a)
#define forn(mp,it) for(it = mp.begin();it!=mp.end();it++)
#define FOR(i,a,n) for(ll i=a;i<n;i++) 
#define FORE(i,a,n) FOR(i,a,n+1)
#define Endl endl
#define eNdl endl
#define enDl endl
#define endL endl

bool check(string a,string b)
{
	FOR(i,0,a.size())
	{
		if((a[i] == b[i])||(a[i]!=b[i]&&a[i] == '?'))continue;
		else return 0;
	}
	return 1;
}
int main()
{
	string s,t;
	cin>>s>>t;
	string ans = "";
	for(int i=0;i+t.size()-1<s.size();i++)
	{
		string tmp = s.substr(i,t.size());
		bool isok = check(tmp,t);
		if(!isok)continue;
		string ma = s;
		for(int j = i;j<=i+t.size()-1;j++)ma[j] = t[j-i];
		for(int j=0;j<ma.size();j++)
			if(!isalpha(ma[j]))ma[j] = 'a';
		if(ans == ""||ans>ma)ans = ma;
	 } 
	if(ans == "")cout<<"UNRESTORABLE"<<Endl;
	else cout<<ans<<endl;
	return 0;
}