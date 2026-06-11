#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<queue>
#include<map>
#include<algorithm>
#include<functional>
using namespace std;
int main(){
 long long n,m;
 bool c[100001];
 scanf("%lld%lld ",&n,&m);
 vector<pair<long long,long long>> pairs(m);
 long long i,j;
 long long x,y;
  
 for(i=0;i<m;i++){
  scanf(" %lld%lld",&x,&y);
   pairs[i]={y,x};
  c[i]=1;
 }
  
 //小さい順sort
 sort(pairs.begin(),pairs.end());
  
 long long ans=m;
 c[0]=1;
 for(i=0;i<m;i++){
  if(c[i]){
   for(j=i+1;j<m;j++){
    if(pairs[j].second<pairs[i].first&&c[j]){
     ans--;
     c[j]=0;
     //printf("ans %lld i %lld j %lld\n",ans,i,j);
    }
   }
  }
 }
 printf("%lld\n",ans);
return 0;}