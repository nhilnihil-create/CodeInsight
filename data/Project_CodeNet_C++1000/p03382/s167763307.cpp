//Binomial
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
using namespace std;
const int inf=2147483647,dx[]={-1,0,1,0},dy[]={0,-1,0,1};// ÉÏ ×ó ÏÂ ÓÒ
const int N=100005,M=1000005,mod=1000000007;
const long long llinf=9223372036854775807ll;
int n,a[N],maxv,minv,ans,val,maxvv;
int main(){
	cin>>n;
	maxv=-999;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxv=max(maxv,a[i]);
	}
	cout<<maxv<<' ';
	maxvv=maxv/2;
	minv=1000000000;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==maxv)
			continue;
		if(maxv%2==0)
			val=abs(a[i]-maxvv);
		else
			val=min(abs(a[i]-maxvv),abs(a[i]-(maxvv+1)));
		if(val<minv)
			minv=val,ans=a[i];
	}
	cout<<ans;
	return 0;
}