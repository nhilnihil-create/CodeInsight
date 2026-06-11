#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
int main()
{

	ll n,p,ans=1,prime=2;
	int cnt=0;
	scanf("%lld%lld",&n,&p);
	if(n==1)
		printf("%lld",p);
	else if(p==1)
		printf("1\n");
	else{
		while(p>1&&prime*prime<=p){
			while(p%prime==0)
			{
				cnt++;
				p/=prime;
				if(cnt==n){
					ans*=prime;
					cnt=0;
				}
			}
			cnt=0;
			if(prime==2) prime++;
			else 
				prime+=2;	
		}
		printf("%lld",ans);
	}
	
	return 0;
}