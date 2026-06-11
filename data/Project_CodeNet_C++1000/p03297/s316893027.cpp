#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int T;
LL a,b,c,d;

inline LL find_min(LL x,LL y,LL z){
	if(x%y>=z) return (x/y+1LL)*y+z;
	else return (x/y)*y+z;
}

inline void solve(){
	cin>>a>>b>>c>>d;
	if(a<b||d<b) {
		puts("No");
		return ;
	}
	if(c>b) {
		puts("Yes");
		return ;
	}
	LL gcd=__gcd(b,d);
	a%=gcd;
	LL tmp=find_min(c,gcd,a);
//	cout<<tmp<<endl;
	if(tmp<b) {
		puts("No");
		return ;
	} else {
		puts("Yes");
		return ;
	}
}

int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}