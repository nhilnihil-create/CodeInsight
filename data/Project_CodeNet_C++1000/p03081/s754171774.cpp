#include <bits/stdc++.h>
#define int long long
#define P pair<int,int>
#define inf (int)(3e18)
#define mod (int)(1e9+7)
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int n,q;
string s;
char t[222222],d[222222];
signed main(){
	cin>>n>>q>>s;
	rep(i,q)cin>>t[i]>>d[i];
	int le=-1,ri=n;
	for(int i=q-1;i>=0;i--){
		if(s[le+1]==t[i]&&d[i]=='L')le++;
		if(s[ri-1]==t[i]&&d[i]=='R')ri--;
		if(le!=-1&&s[le]==t[i]&&d[i]=='R')le--;
		if(ri!=n&&s[ri]==t[i]&&d[i]=='L')ri++;
	}
	cout<<max(0ll,ri-le-1)<<endl;
}
