#include<bits/stdc++.h>
#define reg register
typedef long long ll;
using namespace std;
int L,cnt;
int st[61],to[61],cost[61];
int main(){
	ios::sync_with_stdio(false);
	cin>>L;reg int pos=0;
	for(reg int i=20;i&&(!pos);i--)if(L&(1<<i))pos=i;
	for(reg int i=1;i<pos;i++){
		st[++cnt]=i;to[cnt]=i+1;cost[cnt]=0;
		st[++cnt]=i;to[cnt]=i+1;cost[cnt]=1<<(i-1);
	}
	st[++cnt]=pos;to[cnt]=20;cost[cnt]=0;
	st[++cnt]=pos;to[cnt]=20;cost[cnt]=1<<(pos-1);
	reg int l=1<<pos;
	while(l<L){
		pos=0;for(reg int i=20;i&&(!pos);i--)if((1<<i)&(L-l))pos=i;
		st[++cnt]=pos+1;to[cnt]=20;cost[cnt]=l;l|=1<<pos;
	}
	cout<<20<<' '<<cnt<<endl;
	for(reg int i=1;i<=cnt;i++)
		cout<<st[i]<<' '<<to[i]<<' '<<cost[i]<<endl;
	return 0;
}