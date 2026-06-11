#include<iostream>
#include<algorithm>
const int maxn=100007;
using namespace std;
int n,l[maxn],r[maxn];
long long ans;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>l[i]>>r[i];
	sort(l,l+n+1,cmp);
	sort(r,r+n+1);
	for(int i=0;i<=n;++i){
		if(l[i]-r[i]<=0)break;
		ans+=(l[i]-r[i])<<1;
	}
	cout<<ans<<"\n";
	return 0;
}