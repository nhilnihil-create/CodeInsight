#include<bits/stdc++.h>
using namespace std;
long long n,l,r,t1,t2,t3,t4,mx,mi,mii=4000000000000000000,a[200010],s[200010];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	l=2;
	r=4;
	t1=a[1];
	t2=a[2];
	t3=a[3];
	t4=s[n]-s[3];
	for(int i=3;i<=n;i++)
	{
		while(l<i&&abs(t1-t2)>abs(t1-t2+a[l]*2ll))
		{
            t1+=a[l];
			t2-=a[l];
			l++;
        }
        while(r<=n&&abs(t4-t3)>abs(t3-t4+a[r]*2ll))
		{
            t3+=a[r];
			t4-=a[r];
			r++;
        }
        mi=4000000000000000000;
		mx=-4000000000000000000;
		mi=min(mi,t1);
		mi=min(mi,t2);
		mi=min(mi,t3);
		mi=min(mi,t4);
		mx=max(mx,t1);
		mx=max(mx,t2);
		mx=max(mx,t3);
		mx=max(mx,t4);
        mii=min(mii,mx-mi); 
		t2+=a[i]; 
		t3-=a[i];
	} 
	cout<<mii;
	return 0;
} 