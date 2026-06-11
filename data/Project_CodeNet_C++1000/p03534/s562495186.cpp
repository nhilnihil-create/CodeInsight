#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
using namespace std;
#define inf 1<<29
#define nu 4000005
int n,k;
int maxnum=-inf;
char ch[100005];
int a[3];
int main()
{
   cin>>ch;
   memset(a,0,sizeof(a));
   for(int i=0;i<strlen(ch);i++)
   {
       if(ch[i]=='a') a[0]++;
       else if(ch[i]=='b') a[1]++;
       else a[2]++;
   }
   sort(a,a+3);
   for(int i=2;i>=0;i--)
   {
       if(!a[i]) continue;
       if(a[0]) a[i]-=a[0];
   }
   int flag=1;
   for(int i=0;i<3;i++){
    if(a[i]&&a[i]>1) flag=0;
   }
   if(flag)
    cout<<"YES"<<endl;
   else
    cout<<"NO"<<endl;
    return 0;
}
