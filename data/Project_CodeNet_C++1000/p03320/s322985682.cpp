#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long dig(long long x)
{
	int ans=0;
	while(x){ans+=x%10;x/=10;}
	return ans;
}
double a[101000000];
long long ans[10100000],tot=0;
int main()
{
	ans[1]=1;ans[2]=2;ans[3]=3;ans[4]=4;ans[5]=5;ans[6]=6;ans[7]=7;ans[8]=8;ans[9]=9;
	ans[10]=19;ans[11]=29;ans[12]=39;ans[13]=49;ans[14]=59;ans[15]=69;ans[16]=79;ans[17]=89;ans[18]=99;
	ans[19]=199;ans[20]=299;ans[21]=399;ans[22]=499;ans[23]=599;ans[24]=699;ans[25]=799;ans[26]=899;ans[27]=999;
	int tot=27;
	for(int i=0;i<=999;i++)
	{
		long long w=1;
		for(int j=0;j<=12;j++,w*=10)
		{
			long long k=i*w+(w-1);if(k==0)break;
			bool ok=0;
			for(int a=0;a<=999;a++)
			{
				long long W=1;
				for(int b=0;b<=13;b++,W*=10)
				{
					long long K=a*W+(W-1);//cout<<K<<' '<<k<<endl;
					if(K<=k)continue;
					if(1.0*K/dig(K)<1.0*k/dig(k)){ok=1;break;}
				}
				if(ok)break;
			}
			if(!ok)ans[++tot]=k;
		}
	}
	sort(ans+1,ans+tot+1);tot=unique(ans+1,ans+tot+1)-ans-1;
	int k;scanf("%d",&k);
	for(int i=1;i<=k;i++)printf("%lld\n",ans[i]);return 0;
	/*
	for(int i=1;i<=100000000;i++)
	{
		a[i]=1.0*i/dig(i);
	//	cout<<i<<' '<<dig(i)<<' '<<1.0*i/dig(i)<<endl;
	}
	for(int i=1;i<=100000000;i++)
	{
		bool ok=0;
		for(int j=i+1;j<=100000000;j++)if(a[j]<a[i]){ok=1;break;}
		if(!ok)cout<<i<<endl;
	}*/
	
}