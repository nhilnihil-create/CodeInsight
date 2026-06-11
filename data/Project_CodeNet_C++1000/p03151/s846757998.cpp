#include<bits/stdc++.h>
#define ford(i,a,b) for(int i=(a);i>=b;i--)
#define rep(i,a,b) for(int i=(a);(i)<=(b);(i)++)
#define ll long long
#define re return
#define mp map<int,int>
using namespace std;
ll a[100005],b[100005],sum[100005],cnt,ans;
bool cmp(int x,int y){
	return x>y;
}
int main() {
	int n;
	cin>>n;
	rep(i,1,n)cin>>a[i];
	rep(i,1,n){
		cin>>b[i];
		if(a[i]>b[i]) sum[i]=a[i]-b[i];
		else if(a[i]<b[i]) cnt+=b[i]-a[i],ans++;
	}
	sort(sum+1,sum+1+n,cmp);
	rep(i,1,n){
		if(cnt>0) cnt-=sum[i],ans++;
	}
	if(cnt>0)cout<<-1;
	else cout<<ans;
	re 0;
}
