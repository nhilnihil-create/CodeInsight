#include <iostream>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define ll long long 
ll gcd(ll a,ll b)
{
	return b==0?a:gcd(b,a%b);
}
int main(int argc, char** argv) {
	int T;
	cin>>T;
	while(T--)
	{
		ll a,b,c,d;
		cin>>a>>b>>c>>d;	if(b>a||b>d)
		{
			printf("No\n");
			continue;
		}
		if(c>=b)
		{
			printf("Yes\n");
			continue;
		}
		ll p=gcd(b,d);
		a=a%b;
	
		ll e=((c-a)/p)*p+a;
	//	cout<<e<<endl; 
		if(e<=c)e+=p;//第一个大于c的 
	//	cout<<e<<endl;
		if(e<b)printf("No\n");
		else printf("Yes\n");
	} 
	return 0;
}