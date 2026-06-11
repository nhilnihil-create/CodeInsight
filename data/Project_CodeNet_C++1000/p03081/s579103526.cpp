#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
int n,q,L,R;
string s;
char t[222222],d[222222];
signed main(){
	cin>>n>>q>>s;
	rep(i,q)cin>>t[i]>>d[i];
	int ok=-1,ng=n;
	while(ng-ok>1){
		int mid=(ok+ng)/2;
		int now=mid;
		rep(i,q){
			if(s[now]==t[i]){
				if(d[i]=='L')now--;
				else now++;
			}
			if(now==-1)break;
		}
		if(now==-1)ok=mid;
		else ng=mid;
	}
	L=ok;
	ng=-1,ok=n;
	while(ok-ng>1){
		int mid=(ok+ng)/2;
		int now=mid;
		rep(i,q){
			if(s[now]==t[i]){
				if(d[i]=='L')now--;
				else now++;
			}
			if(now==n)break;
		}
		if(now==n)ok=mid;
		else ng=mid;
	}
	R=ok;
	cout<<max(0ll,R-L-1)<<endl;
	return 0;
}
