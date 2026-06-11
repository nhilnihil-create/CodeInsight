#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum[200000];
ll getval(int l,int r)
{
	if(l==0)
		return sum[r];
	return (sum[r]-sum[l-1]);
}
int check(int l,int r,int mid,ll &a,ll &b)
{
	ll ck[4];
	a=ck[0]=getval(l,mid);
	b=ck[1]=getval(mid+1,r);
	if(ck[0]==ck[1])//相等已经最优 	
		return 0;	
	else if(ck[0]>ck[1])//大于，要求mid向前移动 	
		return -1;
	if((mid+2)>r)
	{//mid已经移动到倒数第二个 
		if(ck[0]<ck[1])//还小，说明前面总和小于最后一个			
			return 0;		
		return -1;//mid前移 
	}
	ck[2]=getval(l,mid+1);
	ck[3]=getval(mid+2,r);
	if(ck[2]==ck[3])
	{//相等已经最优 
		a=ck[2];
		b=ck[3];
		return 0;	
	}		
	if(ck[2]<ck[3])// //mid后移 
		return 1;		
	if((ck[1]-ck[0])>=(ck[2]-ck[3]))	//下面说明由小转大，判别哪个差值小 
	{
		a=ck[2];
		b=ck[3];
	}
	return 0;
}
void find(int l,int r,ll &a,ll &b)
{
	int x=l,y=r;
	int mid,ret;
	while(x<y)
	{
		mid=(x+y)/2;
		ret=check(l,r,mid,a,b);
		if(ret==0)	
			return;		
		else if(ret==1)		
			x=mid;
		else
			y=mid;
	}
	a=getval(l,l);
	b=getval(l+1,r);
}
int main(void)
{
	int n;
	ll tt=0;
	ll res=1e15;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int tmp;
		cin>>tmp;
		tt+=tmp;
		sum[i]=tt;
	}
	for(int i=2;i<n-1;i++)
	{
		ll  a[4];
		find(0,i-1,a[0],a[1]);
		find(i,n-1,a[2],a[3]);					
		sort(a,a+4);
		res=min(res,a[3]-a[0]);
	}
	cout<<res;
	return 0;
}