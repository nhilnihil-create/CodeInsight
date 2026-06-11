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
#include<functional>
#include<deque>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int main(){
  int i,n,m,p,q;
  vector<P> x;
  vector<vector<int> > y(100010);
  scanf("%d %d\n",&n,&m);
  for(i=0;i<m;i++){
    scanf("%d %d\n",&p,&q);
    x.push_back(P(p,q));
    y[p].push_back(q);
  }
  for(i=1;i<=n;i++){
    sort(y[i].begin(),y[i].end());
    y[i].erase(unique(y[i].begin(),y[i].end()),y[i].end());
  }
  for(i=0;i<m;i++){
    int max=y[x[i].first].size(),min=-1,mid;
    while(abs(min-max)>1){
      mid=(min+max)/2;
      if(y[x[i].first][mid]<=x[i].second){
        min=mid;
      }
      else{
        max=mid;
      }
    }
    printf("%06d%06d\n",x[i].first,min+1);
  }
  return 0;
}