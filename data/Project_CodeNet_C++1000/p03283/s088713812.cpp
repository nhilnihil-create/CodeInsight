#include<math.h>
#include<cmath>
#include<bitset>
#include<stdio.h>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<utility>
using namespace std;
int main(){
  int s[510][510],n,m,Q,l,r,p,q,a[510][510],i,j;
  scanf("%d %d %d\n",&n,&m,&Q);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      a[i][j]=0;
    }
  }
  for(i=0;i<m;i++){
    scanf("%d %d\n",&l,&r);
    l--,r--;
    a[0][r]++;
    a[l+1][r]--;
  }
  for(i=0;i<n;i++){
    s[0][i]=0;
    s[i][0]=0;
  }
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      s[i+1][j+1]=s[i][j+1]+s[i+1][j]-s[i][j]+a[i][j];
    }
  }
  for(i=0;i<Q;i++){
    scanf("%d %d\n",&p,&q);
    printf("%d\n",s[p][q]);
  }
  return 0;
}