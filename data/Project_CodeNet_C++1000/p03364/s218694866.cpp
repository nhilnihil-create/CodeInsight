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
*/

ll n,ans=0;
string s[310];

bool is_symmerty(ll a,ll b){
	bool ok=true;
	rep(i,n){
		rep(j,n){
			if(s[(i-a+n)%n][(j-b+n)%n]!=s[(j-a+n)%n][(i-b+n)%n]){
				ok=false;
				break;
			}
		}
	}
	return ok;
}

void init(){
	cin>>n;
	rep(i,n)cin>>s[i];
}

int main(void){
	init();
	rep(i,n)if(is_symmerty(i,0))ans+=n;
	cout<<ans<<endl;
	return 0;
}