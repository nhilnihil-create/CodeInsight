
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define endl "\n"
#define se second
#define ls( s) (s&(-s))
#define ll long long
#define inf 0x3f3f3f3f
#define fast    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N = 2e5+10;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
const ll mod =    2019;
int h,w,n;
int xf,yf;
string s,t;
bool go(int cur,int mx,char c1,char c2)
{
	int l=cur,r=cur;
	for(int i=0;i<n;i++)
	{
		if(s[i]==c1)
		l--;
		else if(s[i]==c2)
		r++;
		if((!l)||(r>mx))
		return true;
		if(t[i]==c1)
		r--;
		if(t[i]==c2)
		l++;
		r=max(r,1);
		l=min(l,mx);
	}
	return false;
}
int main()
{  fast
   cin>>h>>w>>n>>xf>>yf;
   cin>>s>>t;
  if(go(xf,h,'U','D')||go(yf,w,'L','R'))cout<<"NO";
  else
  cout<<"YES";
}
