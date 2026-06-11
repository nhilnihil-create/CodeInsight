#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<numeric>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i = 0;i<((int)(n));i++)
#define reg(i,a,b) for(int i = ((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i = ((int)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(int i = ((int)(b));i>=((int)(a));i--)
typedef long long ll;
typedef pair<ll, ll> mp;

/*
AC
同時にとるなら、帰りにとる
*/

ll n,x,a[200010],dp[200010];
unsigned long long ans=1e18;

int main(void){
	dp[0]=0;
	cin>>n>>x;
	reg(i,1,n){
		cin>>a[i];
		dp[i]=a[i]+dp[i-1];
	}
	reg(i,1,n){//ゴミを捨てる回数＝往復回数
		unsigned long long sum=n*x+i*x;
		//なるべく均等になるように分配
		rep(j,n+2){
			if(n-j*i<=0)break;
			sum+=(dp[n-j*i]-dp[max(n-(j+1)*i,(ll)0)])*max(5,(j+1)*2+1);
		}
		ans=min(ans,sum);
	}
	cout<<ans<<endl;
	return 0;
}