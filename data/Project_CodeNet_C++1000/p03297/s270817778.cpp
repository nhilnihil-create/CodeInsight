#include<bits/stdc++.h>
using namespace std;
int t;
long long a,b,c,d,gg,tmp,x;
void solve(){
	cin>>a>>b>>c>>d;
	if(b>a){
		cout<<"No"<<endl;
		return;
	}
	if(b>d){
		cout<<"No"<<endl;
		return;
	}
	gg=__gcd(b,d);
	tmp=(c-b+1)/gg;
	if((c-b+1)<0)
		tmp--;
	x=tmp*gg+a%gg;
	if(x<(c-b+1))
		x+=gg;
	if(x>=0) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>t;
	while(t--)
		solve();
	return 0;
}
