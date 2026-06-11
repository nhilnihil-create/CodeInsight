#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2000;
ll x[N],y[N],sumx,sumy;int n;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>x[i]>>y[i];
		if((x[i]+y[i]+x[1]+y[1])&1){
			cout<<"-1\n";
			return 0;
		}
	}
	int op=(x[1]+y[1])&1;
	cout<<40-op<<'\n';if(!op)cout<<1<<' ';
	for(int i=0;i<39;++i)cout<<(1ll<<i)<<" \n"[i==38];
	for(int i=1;i<=n;++i){
		if(!op)cout<<'D',y[i]++;
		for(int j=0;j<39;++j){
			if(x[i]>>j&1){
				if((((x[i]+(1ll<<j))^y[i])>>(j+1)&1)^(j==38))cout<<'L',x[i]+=1ll<<j;
				else cout<<'R',x[i]-=1ll<<j;
			}else{
				if((((y[i]+(1ll<<j))^x[i])>>(j+1)&1)^(j==38))cout<<'D',y[i]+=1ll<<j;
				else cout<<'U',y[i]-=1ll<<j;
			}
		}
		cout<<'\n';
	}
	return 0;
}
