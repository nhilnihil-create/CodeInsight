#include<bits/stdc++.h>
using namespace std;
const int l2=15000;
const int l3=5000;
const int N=31000;
int n,tot;
int a[N],cnt=0;
int main()
{
  scanf("%d",&n);
  int even=n/2*2;
  if(n==3) return printf("2 5 63\n"),0;
  int c2=0,c3=0;
  for(int i=1;i<=min(l3,even-2);i++) a[++tot]=(2*i-1)*3,c3+=2*i-1;
  n-=tot;
  for(int i=1;i<=n;i++) a[++tot]=i*2,c2+=i;
  c2%=3;
  c2=(3-c2)%3;
  a[tot]+=c2*2;
  for(int i=1;i<=tot;i++) printf("%d ",a[i]);
  printf("\n");
  return 0;
}