#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+10;
typedef long long ll;
int a[MAXN],n;
ll srk[MAXN][2],frk[MAXN][2];
inline ll Abs(ll num){
	return num>0?num:-num;
}
bool check(int pos1,ll sum1,ll sum2){
	ll t1 = Abs(sum1-sum2-sum2);
	ll t2 = Abs(sum1-sum2-sum2-a[pos1]-a[pos1]);
	if(t2<t1)return true;
	else return false;
}
ll BigOf4(ll e,ll b,ll c,ll d){
	return max(max(e,b),max(c,d));
}
ll SmaOf4(ll b,ll c,ll d,ll e){
	return min(min(b,c),min(d,e));
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	ll sum=0,sum1=0;
	sum=sum1=a[1];
	int pos=1;
	for(int i=2;i<=n;i++){
		sum+=a[i];
		while(pos+1<i&&check(pos+1,sum,sum1)){
			pos++;
			sum1+=a[pos];
		}
		frk[i][0]=sum-sum1;
		frk[i][1]=sum1;
	//	cout<<sum<<" "<<sum1<<" "<<i<<endl;
	}
	sum=sum1=a[n];
	pos=n;
	for(int i=n-1;i>=1;i--){
		sum+=a[i];
		while(pos-1>i&&check(pos-1,sum,sum1)){
			pos--;
			sum1+=a[pos];
		}
		srk[i][0]=sum-sum1;
		srk[i][1]=sum1;
	}
	ll ans=1000000000000000LL;
	for(int i=2;i+2<=n;i++){
		ans=min(ans,BigOf4(frk[i][0],frk[i][1],srk[i+1][0],srk[i+1][1])-SmaOf4(frk[i][0],frk[i][1],srk[i+1][0],srk[i+1][1]));
	}
	cout<<ans;
	return 0;
}
