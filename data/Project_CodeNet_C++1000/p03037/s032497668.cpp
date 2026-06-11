#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
//#define ll long long
//#define maxn -99999
using namespace std;
int a[200005];
int book[200005];
//bool cmp(int x,int y)
//{
//	return x>y;
//}
 //int ll=999999999,rr=-999999999;
int main()
{
   int n,m;
   int l,r,t;
  
   scanf("%d %d",&n,&m); 
   t=m;
   memset(book,0,sizeof(book));
   while(t--)
   {
   	 scanf("%d %d",&l,&r);
   	for(int i=l;i<=r;i++)
   	{
   		book[i]++;
	   }
//	   ll=min(ll,l);
//	   rr=max(rr,r);
	   
   }
   //sort(book,book+n,cmp);
   int ans=0;
   for(int i=1;i<=n;i++)
   {
   	 if(book[i]==m)
   	 ans++;
   	 //cout<<book[i]<<endl;
   }
   printf("%d\n",ans);
	return 0;
}