#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define ll long long
using namespace std;
int k;
void init(){scanf("%d",&k);}
vector<int>decompose(ll x){
	vector<int>tmp;
	while(x)tmp.push_back(x%10),x/=10;
	return tmp;
}
ll to_number(vector<int>x){
	ll tmp=0;
	for(int i=x.size()-1;~i;--i)(tmp*=10)+=x[i];
	return tmp;
}
ll sum(ll x){
	ll s=0;
	while(x)s+=x%10,x/=10;
	return s;
}
inline ll f(ll x){
	vector<int>dx=decompose(x);
	double mn=1e18;ll ne=-1;
	for(int i=0;i<dx.size();++i)
	for(int d=dx[i];d<=9;++d){
		vector<int>dy=dx;
		dy[i]=d;for(int j=0;j<i;++j)dy[j]=9;
		ll y=to_number(dy),sy=sum(y);
		if((double)y/sy<mn)mn=(double)y/sy,ne=y;
	}
	return ne;
}
void solve(){
	ll s=1;
	for(int i=1;i<=k;++i,s=f(s+1))printf("%lld\n",s);
}
int main(){
	init();
	solve();
	return 0;
}