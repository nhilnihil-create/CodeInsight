#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
	int Q;
	long long A,B;
	scanf("%d",&Q);
	for(int i=1;i<=Q;i++)
	{
		scanf("%lld%lld",&A,&B);
		long long pro=1LL*A*B;
		long long cnt=0;
		long long s=sqrt(pro)-1;
		cnt=2*s;
		cnt-=(A<=s)+(B<=s);
		s++;
		bool flag=false;
		if(s!=A&&(s+1)!=B&&s*(s+1)<pro)
			cnt++,flag=true;
		if((s+1)!=A&&s!=B&&s*(s+1)<pro)
			cnt++,flag=true;
		if(!flag&&s!=A&&s!=B&&s*s<pro)
			cnt++;
		
		printf("%lld\n",cnt);
	}
	
	return 0;
}
