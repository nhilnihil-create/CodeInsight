#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<queue>
using namespace std;
int main(){
 long long hy,wx,i,j;
 queue<long long>quex,quey;
 scanf("%lld%lld ",&hy,&wx);
 char a[1005][1005];//配列はx,yの順に入れる
 for(i=1;i<=hy;i++){
  for(j=1;j<=wx+1;j++){
   scanf("%c",&a[j][i]);
  // printf("i %d j %d %c\n",i,j,a[j][i]);
   if(a[j][i]=='#'){
    quex.push(j);quey.push(i);
   }
  }
 }
 long long num[1005][1005]={0};
 long long u,v,ans=0;
  
 while(!quex.empty()){
  u=quex.front();
  v=quey.front();
 // printf("\nu %d v %d\n",u,v);
  quex.pop();quey.pop();
   
  if(a[u-1][v]=='.'){
     a[u-1][v]='#';
     num[u-1][v]=num[u][v]+1;
     ans=num[u-1][v];
     quex.push(u-1);quey.push(v);
    }
   
  if(a[u+1][v]=='.'){
     a[u+1][v]='#';
     num[u+1][v]=num[u][v]+1;
     ans=num[u+1][v];
     quex.push(u+1);quey.push(v);
    }
   
  if(a[u][v-1]=='.'){
     a[u][v-1]='#';
     num[u][v-1]=num[u][v]+1;
     ans=num[u][v-1];
     quex.push(u);quey.push(v-1);
    }
   
  if(a[u][v+1]=='.'){
     a[u][v+1]='#';
     num[u][v+1]=num[u][v]+1;
     ans=num[u][v+1];
     quex.push(u);quey.push(v+1);
    }
  
 }
  
 printf("%lld\n",ans);
return 0;}
