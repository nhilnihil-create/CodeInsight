#include <bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define elif else if
using namespace std;
int a,b,c,d,e,f;
signed main()
{
	cin>>a>>b>>c;
	rep(i,a){
		cin>>d>>e;
		if(d>=b&&e>=c){
			f++;
		}
	}
	cout<<f;
}