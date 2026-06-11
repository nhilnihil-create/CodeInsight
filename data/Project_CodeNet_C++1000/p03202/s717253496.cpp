#include <bits/stdc++.h>
#define all(vec) vec.begin(),vec.end()
#define mp make_pair
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
const ll INF=1LL<<30;
const ll LINF=1LL<<60;
const double eps=1e-5;
template<typename T>void chmin(T &a,T b){a=min(a,b);};
template<typename T>void chmax(T &a,T b){a=max(a,b);};
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
vector<ll> a;
int n;
bool check(ll s){
	map<ll,ll> mp;
	for(int i=0;i<n-1;i++){
		ll x=a[i+1];
		if(a[i]<x)continue;
		while(mp[x]+1LL>=s&&x>0)--x;
		if(x==0LL)return false;
		mp[x]++;
		auto itr=mp.end();--itr;
		while(itr->first>x){
			mp.erase(itr);
			--itr;
		}
	}
	return true;
}
int main(){
	cin>>n;
	a.resize(n);
	for(int i=0;i<n;i++)cin>>a[i];
    bool f=true;
    for(int i=1;i<n;i++){
        if(a[i-1]>=a[i])f=false;
    }
    if(f){
        cout<<1<<endl;
        return 0;
    }
	ll ng=1,ok=INF;
	while(ok-ng>1){
		ll mid=(ng+ok)/2;
		if(check(mid)){
			ok=mid;
		}else{
			ng=mid;
		}
	}
	cout<<ok<<endl;
}
