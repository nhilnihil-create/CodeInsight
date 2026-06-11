#include <bits/stdc++.h>
#define rep(i,a,b) for(i=a;i<b;i++)
#define per(i,b,a) for(i=b;i>=a;i--)
#define For(i,a,b) for(i=a;i<=b;i++)
#define Forenska(it,c) for(register __typeof(c.begin()) it=c.begin();it!=c.end();it++)
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define GREATER(x) x,vector<x>,greater<x>
using namespace std;
int i,j;
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pLL;
typedef vector<int> vec;
typedef vector<LL> vecL;
typedef vector<pii> vecP;
typedef vector<pLL> vecPL;
typedef vector<string> vecS;
typedef vector<vec> mat;
typedef complex<double> point;
const long double PI=3.14159265358979323846264338327950288;
const LL INFLL=0x3f3f3f3f3f3f3f3f;
const int INF=0x3f3f3f3f;
const long double EPS=1e-10;
int read()
{
	int x=0;
	char ch=' ';
	bool flag=false;
	while(!isdigit(ch))
	{
		if(ch=='-')flag=true;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return flag?-x:x;
}

int main()
{
	string s;
	cin>>s;
	int alpha=s.find("FESTIVAL");
	while(s.find("FESTIVAL",alpha+1)!=string::npos)
	{
		alpha=s.find("FESTIVAL",alpha+1);
	}
	s.erase(alpha);
	cout<<s<<endl;
	return 0;
}

