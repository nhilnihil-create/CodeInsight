#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
//const ll mod=998244353;
const ll mod=1000000007;
ll GCD(ll a,ll b) {return b ? GCD(b,a%b):a;}
ll LCM(ll c,ll d){return c/GCD(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int main(){
	ll m,k;
	cin>>m>>k;
	if(m==1&&k==0){
		//まさかのサンプルがコーナー
		cout<<0<<" "<<0<<" "<<1<<" "<<1<<"\n";
		return 0;
	}
	ll d=0;
	deque<ll> deq;
	if(k!=0){
	for(int i=0;i<(1<<m);i++){
		if(i==k)continue;
		d^=i;
	}
	if(d!=k){
		cout<<-1<<"\n";
		return 0;
	}
	}
	deq.push_back(k);
	for(int i=0;i<(1<<m);i++){
		if(i==k)continue;
		deq.push_front(i);
		deq.push_back(i);
	}
	deq.push_back(k);
	while(deq.size()){
		cout<<deq.front()<<(deq.size()==1?"\n":" ");
		deq.pop_front();
	}

}