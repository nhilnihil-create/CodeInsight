#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll x[101000] , w[101000] , n , c , ans , Max1[101000] ,Max2[101000], sum;
ll read()
{
	ll x=0; ll f=1;char s=getchar();
	for(;s<'0'||s>'9';s=getchar()) if(s=='-') f=-1;
	for(;s>='0'&&s<='9';s=getchar()) x=(x<<3)+(x<<1)+s-48;
	x*=f;
    return x;
}

int main()
{
	n = read();c = read();
	for(int i = 1;i <= n;++i) 
	 x[i] = read() , w[i] = read();
	for(int i = 1;i <= n;++i)
	 sum += w[i] , Max1[i] = max( Max1[i-1] , sum - x[i]);
	sum = 0;
	ans = Max1[n];
	for(int i = n;i >= 1;--i)
	 sum += w[i] , Max2[i] = max ( Max2[i+1] , sum - (c - x[i]));
	sum = 0;ans = max(ans , Max2[1]);
	for(int i = 1;i <= n;++i)
	 sum += w[i],ans = max ( ans , Max2[i + 1] + sum - x[i] * 2);
    sum = 0;
    for(int i = n;i >= 1;--i)
     sum += w[i],ans = max ( ans , Max1[i - 1] + sum - (c - x[i]) * 2);
    printf("%lld",ans);
	return 0;
}