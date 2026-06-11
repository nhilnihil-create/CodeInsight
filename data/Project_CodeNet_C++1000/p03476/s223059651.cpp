#include<bits/stdc++.h>
using namespace std;

int main()
{
  int Q;scanf("%d",&Q);
  bool is_prime[100001],alike[100001];
  fill(is_prime,is_prime+100001,true);fill(alike,alike+100001,false);
  is_prime[0]=false,is_prime[1]=false;
  for(int i=2;i<100001;i++)
  {
    if(!is_prime[i])continue;
    for(int j=i*2;j<100001;j+=i)is_prime[j]=false;
  }
  for(int i=3;i<100001;i+=2)if(is_prime[(i+1)/2]&&is_prime[i])alike[i]=true;
  int count_prime[100001];fill(count_prime,count_prime+100001,0);
  for(int i=3;i<100001;i+=2)count_prime[i]=count_prime[i-2]+alike[i];
  for(int l,r,i=0;i<Q;i++)
  {
    scanf("%d %d",&l,&r);
    int ans=count_prime[r]-count_prime[l];
    if(alike[l])ans++;
    printf("%d\n",ans);
  }
}