#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() puts("okkkkkkkk")
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
 
using namespace std;
 
typedef long long LL;
#define int LL
 
const int inf = 1e9;
int a;
int s(int x){int r=0;while(x){r+=x%10;x/=10;}return r;}
int check(int x){for(int i=x+1;i<=x+10000;i++)if(x*s(i)>i*s(x))return 0;return 1;}
LL f[21];
signed main(){
	int n;scanf("%lld",&n);
	f[0]=1;for(int i=1;i<=18;i++)f[i]=f[i-1]*10ll;
	LL ans=1,cd=0;while(n--){
		printf("%lld\n",ans);
		if((ans+f[cd])*s(ans+f[cd]*2)>(ans+f[cd]*2)*s(ans+f[cd]))++cd;
		ans+=f[cd];
	}
 
	return 0;
}