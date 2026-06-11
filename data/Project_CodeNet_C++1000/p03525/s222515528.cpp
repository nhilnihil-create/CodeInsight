#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i = 0;i<((ll)(n));i++)
#define reg(i,a,b) for(ll i = ((ll)(a));i<=((ll)(b));i++)
#define irep(i,n) for(ll i = ((ll)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(ll i = ((ll)(b));i>=((ll)(a));i--)
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

/*
0に近い方から左右に交互に振り分けるのが最適
よく見る形
*/

ll n,ans=99,l=0,r=0;
map<ll,ll> m;

void init(){
	cin>>n;
	rep(i,n){
		ll d;
		cin>>d;
		m[d]++;
	}
}

int main(void){
	init();
	if(m[0]>0)ans=0;
	reg(i,1,11){
		if(m[i]>2){
			ans=0;
		}
		if(m[i]==2){
			ans=min({ans,i-l,i-r,24-2*i});
			l=i;
			r=i;
		}
		if(m[i]==1){
			if(l<r){
				ans=min({ans,i-l,24-i-r});
				l=i;
			}else{
				ans=min({ans,i-r,24-i-l});
				r=i;
			}
		}
	}
	if(m[12]==1)ans=min({ans,12-l,12-r});
	if(m[12]==2)ans=0;
	cout<<ans<<endl;
	return 0;
}