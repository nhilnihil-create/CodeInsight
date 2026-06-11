//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,len;
int a[200005];
vector<pair<int,int> >now;//(char,len)
bool ok(int x){
	now.clear();len=0;
	for(int i=1;i<=n;i++){
		if(a[i]>len){
			now.push_back(make_pair(1,a[i]-len));
		}else{
			int Char;
			while(len>=a[i]){
				len-=now.back().second;
				Char=now.back().first;
				now.pop_back();
			}
			if(Char<x){
				if(len!=a[i]-1){
					now.push_back(make_pair(Char,a[i]-1-len));
				}
				now.push_back(make_pair(Char+1,1));
			}else{
				while(now.size()&&now.back().first==x)len-=now.back().second,now.pop_back();
				if(!now.size())return false;
				Char=now.back().first;int tmp=now.back().second;
				now.pop_back();
				if(tmp>1)now.push_back(make_pair(Char,tmp-1));
				now.push_back(make_pair(Char+1,1));
				if(len<a[i])now.push_back(make_pair(1,a[i]-len));
			}
		}
		len=a[i];
	}
	return true;
}
int main(){
//	freopen("data.txt","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int L=0,R=n+5;
	while(R-L>1){
		int mid=(L+R)/2;
		if(ok(mid))R=mid;
		else L=mid;
	}
	cout<<R<<endl;
	return 0;
}