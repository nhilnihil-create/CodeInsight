#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define eps LDBL_EPSILON
#define moder 1000000007
#define int long long
#define double long double
#define ll long long
#define INF LLONG_MAX/3
#define P pair<int,int>
#define prique priority_queue<int,vector<int>,greater<int>>
#define ggr getchar();getchar();return 0
using namespace std;
int n,q;
string s;
char t[200010],d[200010];
bool func(int x,bool b){
	int now=x;
	if(!b){
		rep(i,q){
			if(t[i]==s[now]&&d[i]=='L')now--;
			if(t[i]==s[now]&&d[i]=='R')now++;
			if(now==-1)break;
		}
		if(now==-1)return true;
		return false;
	}
	else{
		rep(i,q){
			if(t[i]==s[now]&&d[i]=='R')now++;
			if(t[i]==s[now]&&d[i]=='L')now--;
			if(now==n)break;
		}
		if(now==n)return true;
		else return false;
	}
}
signed main(){
	cin>>n>>q>>s;
	rep(i,q)cin>>t[i]>>d[i];
	int mi=0,ma=n-1;
	while(ma-mi>1){
		int md=(mi+ma)/2;
		if(func(md,false))mi=md;
		else ma=md;
	}
	int ans;
	if(func(mi,false)){
		if(func(ma,false))mi++;
		ans=mi+1;
	}
	mi=0,ma=n-1;
	while(ma-mi>1){
		int md=(mi+ma)/2;
		if(func(md,true))ma=md;
		else mi=md;
	}
	if(func(ma,true)){
		if(func(mi,true))ma--;
		ans+=n-ma;
	}
	cout<<n-min(n,ans)<<endl;
	ggr;
}