
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
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
	cin>>s;
	int n;
	n=s.size();
	bool ok=true;
	if(s[0]=='0'||s[n-1]=='1')
	ok=false;

	for(int i=0;i<n-1;i++)
	{
		ok=ok&(!((s[i]-'0')^(s[n-2-i]-'0')));
	//	cout<<ok<<endl;
}

if(!ok)
{
	cout<<-1;
	return 0;
}
int cur=1;
for(int i=1;i<n;i++)
{
	cout<<cur<<" "<<i+1<<endl;
	if(s[i-1]=='1')
	cur=i+1;
}
}
