#include<queue>
#include<stack>
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
typedef long long ll;
typedef pair<int,int> P;
const int INF=(1<<29);
int main(){
  int h,w,i,j,a[510][510],sum=0;
  vector<int> b,c,d,e;
  cin >> h >> w;
  for(i=1;i<=h;i++){
    for(j=1;j<=w;j++){
      scanf("%d ",&a[i][j]);
      sum+=a[i][j];
      if(a[i][j]%2==0){
        a[i][j]=0;
      }
      else{
        a[i][j]=1;
      }
    }
  }
  int k=0;
  for(i=1;i<=h;i++){
    if(i%2==1){
      for(j=1;j<=w;j++){
        if(a[i][j]==1 && k==0){
          k=1;
        }
        else if(a[i][j]==1 && k==1){
          k=0;
        }
        if(k==1 && j==w){
          b.push_back(i);
          c.push_back(j);
          d.push_back(i+1);
          e.push_back(j);
        }
        else if(k==1){
          b.push_back(i);
          c.push_back(j);
          d.push_back(i);
          e.push_back(j+1);
        }
      }
    }
    else{
      for(j=w;j>=1;j--){
        if(a[i][j]==1 && k==0){
          k=1;
        }
        else if(a[i][j]==1 && k==1){
          k=0;
        }
        if(k==1 && j==1){
          b.push_back(i);
          c.push_back(j);
          d.push_back(i+1);
          e.push_back(j);
        }
        else if(k==1){
          b.push_back(i);
          c.push_back(j);
          d.push_back(i);
          e.push_back(j-1);
        }
      }
    }
  }
  if(sum%2==1){
    b.pop_back(),c.pop_back(),d.pop_back(),e.pop_back();
  }
  printf("%d\n",b.size());
  for(i=0;i<b.size();i++){
    printf("%d %d %d %d\n",b[i],c[i],d[i],e[i]);
  }
  return 0;
}