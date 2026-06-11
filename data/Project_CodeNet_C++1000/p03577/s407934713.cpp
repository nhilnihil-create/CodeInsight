#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define elif else if
string a;
signed main()
{
	cin>>a;
	a.erase(a.begin()+(a.size()-8),a.begin()+a.size());
	cout<<a;
}