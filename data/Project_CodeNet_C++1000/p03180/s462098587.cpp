#include<functional>
#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdlib>
#include<utility>
#include<string>
#include<cstdio>
#include<vector>
#include<bitset>
#include<cmath>
#include<ctime>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
using namespace std;
const int inf=2147483647,dx[]={-1,0,1,0},dy[]={0,-1,0,1};// 上 左 下 右
const int N=100005,M=1000005,K=200005,mod=1000000007;
const long long llinf=9223372036854775807ll;
//int & long long
long long n,a[20][20],dp[(1<<17)];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	for(int i=0;i<(1<<n);i++)
		for(int j=1;j<=n;j++)//hong
			if(i&(1<<(j-1)))
			{
				dp[i]=dp[i^(1<<(j-1))];
				for(int k=1;k<=n;k++)//lie
					if(i&(1<<(k-1)))
						dp[i]+=a[k][j];
			}
	for(int i=0;i<(1<<n);i++)
		for(int j=i;j>0;j=((j-1)&i))
			dp[i]=max(dp[i],dp[j]+dp[i^j]);
	cout<<dp[(1<<n)-1];
	return 0;
}