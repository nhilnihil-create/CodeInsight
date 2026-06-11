#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<ctime>
#include<vector>
#include<set>
#include<map>
#include<stack>
using namespace std;
const int LOG = 20;
int ans[1100],ans2[1100],ans3[1100];
int main(){
      int n,m=0,l,i,j,k;
      scanf("%d",&l);
      for(i=0;i<=LOG;i++)
        if((1<<i)>l){
          n=i;
          break;
        }
      for(i=1;i<n;i++){
      	ans[++m]=i;
      	ans2[m]=i+1;
      	ans3[m]=0;
      	ans[++m]=i;
      	ans2[m]=i+1;
      	ans3[m]=1<<(i-1);
      }
      int t=1<<(n-1);
      l-=t;
      for(i=n-1;i>0;i--)
	    if((1<<(i-1))<=l){
      	ans[++m]=i;
      	ans2[m]=n;
      	ans3[m]=t;
      	t+=1<<(i-1);
      	l-=1<<(i-1);
      }
      printf("%d %d\n",n,m);
      for(i=1;i<=m;i++)
        printf("%d %d %d\n",ans[i],ans2[i],ans3[i]);
	  return 0;
}