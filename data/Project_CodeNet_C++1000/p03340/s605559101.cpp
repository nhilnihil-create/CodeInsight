#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define rep(i , x , n)  for(int i = x ; i <= n ; i ++) 
#define per(i , n , x)  for(int i = n ; i <= x ; i --) 
using namespace std ;
typedef long long ll ;
typedef pair<int , int> pii ;
const int inf = 0x3f3f3f3f ;
const int maxn = 2e5 + 5 ;
const int maxm = 1005 ;
int n ;
int cnt = 0 ;
ll a[maxn] , b[maxn] , num[maxn] ;
void init()
{
	for(int i = 1 ; i <= n ; i ++)
	{
		b[++ cnt] = a[i] ;
		num[cnt] = 1 ;
		if(a[i] == 0)
		{
			int j = i ;
			while(j + 1 <= n && a[j + 1] == a[j])  j ++ ;
			num[cnt] = j - i + 1 ;
			i = j ;
		}
	}
	n = cnt ;
}
int main()
{
	ll ans = 0 ;
	scanf("%d" , &n) ;
	for(int i = 1 ; i <= n ; i ++)  scanf("%lld" , &a[i]) ;
	init() ;
	for(int i = 1 ; i <= n ; i ++)
	{
		int up = min(i + 45 , n) ;
		ll sum1 = 0 , sum2 = 0 ;
		for(int j = i ; j <= up ; j ++)
		{
			sum1 ^= b[j] ;
			sum2 += b[j] ;
			if(sum1 == sum2)  
			{
				if(i == j && b[i] == 0)  ans += num[i] * (num[i] + 1) / 2 ;
				else  ans += num[i] * num[j] ;
			}			
		}
	}
	printf("%lld\n" , ans) ;
	return 0 ;
}