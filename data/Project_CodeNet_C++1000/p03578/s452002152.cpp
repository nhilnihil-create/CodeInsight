#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
int main()
{
	int n;cin>>n;
	vector<int> d(n);
	int i;
	rep(i,n)cin>>d[i];
	int m;cin>>m;
	vector<int> t(m);
	rep(i,m)cin>>t[i];
	sort(all(d));
	sort(all(t));
	int nowd=0;
	int nowt=0;
	while(nowd<n&&nowt<m)
	{
		if(d[nowd]==t[nowt])
		{
			nowd++;
			nowt++;
		}
		else nowd++;
	}
	if(nowt==m)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
