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

ll n,ans=99,p[2]={},d[51];

void init(){
	cin>>n;
	rep(i,n)cin>>d[i];
	sort(d,d+n);
}

int main(void){
	init();
	rep(i,n){
		ans=min({ans, d[i]-p[i%2], 24-d[i]-p[(i+1)%2]});
		p[i%2]=d[i];
	}
	cout<<ans<<endl;
	return 0;
}