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
#include<list>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int main(){
  int i,j,n,k,x;
  double ans=0;
  cin >> n >> k;
  for(i=1;i<=n;i++){
    j=i,x=0;
    while(j<k){
      j=j*2;
      x++;
    }
    double ans1=1/double(n);
    for(j=0;j<x;j++){
      ans1=ans1/2;
    }
    ans+=ans1;
  }
  printf("%.12lf\n",ans);
  return 0;
}