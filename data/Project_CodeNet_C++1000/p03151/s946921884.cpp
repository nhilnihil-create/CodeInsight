#include<iostream>
#include<queue>
#include<string>
#include<cmath>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<set>
#include<map>
#include<utility>
#include<vector>
#include<stack>
#include<sstream>
#include<algorithm>
using namespace std;
/****************************/
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pair<int,int> >
#define qi queue<int>
#define mii map<int,int>
#define msi map<string,int>
#define vs vector<string>
#define vc vector<char>
/****************************/
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep2(i,n) for(ll i=(n)-1;i>=0;i--)
#define rep3(i,a,n) for(ll i=(a);i<(n);i++)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define pi 3.1415926535897932384626433832795
#define zero(n) memset(n,0,sizeof(n));
#define SZ(n) n.size()
#define ss st.st
#define sn st.nd 
/****************************/
int n;
int a[100010];
int b[100010];
ll numa,numb;
vi c;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
    cin>>n;
    rep(i,n)
    { 
    	cin>>a[i];
    	numa+=a[i];
	}
	rep(i,n)
	{
		cin>>b[i];
		numb+=b[i];
	}
	if(numa<numb)
	{
		cout<<"-1";
		return 0;
	}
	ll neednum=0;
	int ans=0;
	rep(i,n)
	{
		if(a[i]<b[i])
		{
			neednum+=b[i]-a[i];
			ans++;
		}
		c.pb(a[i]-b[i]);
	}
	sort(c.begin(),c.end(),cmp);
	rep(i,SZ(c))
	{
		if(neednum<=0)
		{
			break;
		}
		ans++;
		neednum-=c[i];
	}
	cout<<ans;
    return 0;
}