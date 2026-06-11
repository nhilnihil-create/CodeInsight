#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<utility>
using namespace std;
int main(){
  pair<int,int> a[110];
  pair<int,int> b[110];
  int n,ans=0,i,j,min=(1<<29),k=-1;
  scanf("%d\n",&n);
  for(i=0;i<n;i++){
    scanf("%d %d\n",&a[i].first,&a[i].second);
  }
  for(i=0;i<n;i++){
    scanf("%d %d\n",&b[i].first,&b[i].second);
  }
  sort(a,a+n,greater<pair<int,int> >() );
  sort(b,b+n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(a[i].first<b[j].first && a[i].second<b[j].second && b[j].second<min){
        min=b[j].second,k=j;
      }
    }
    if(k!=-1){
      ans++,b[k].first=0,b[k].second=0;
    }
    k=-1,min=(1<<29);
  }
  printf("%d\n",ans);
  return 0;
}