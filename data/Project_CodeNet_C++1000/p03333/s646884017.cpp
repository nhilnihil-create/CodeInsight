#include<cstdio>
#include<iostream>
#include<vector>
#include<tuple>
#include<queue>
#include<algorithm>
#include<string.h>
#include<map>

using namespace std;
typedef pair<int,int> P;

int main(int argc, char* argv[]){
  int n;
  scanf("%d",&n);
  vector<int>l(n+1);
  vector<int>r(n+1);
  int t1,t2;
  for(int i=0;i<n;i++){
    scanf("%d%d",&t1,&t2);
    l[i]=t1;
    r[i]=t2;
  }
  l[n]=0;
  r[n]=0;
  sort(l.begin(),l.end(),greater<int>());
  sort(r.begin(),r.end());
  long long int ans=0;
  long long int temp=0;
  for(int i=0;i<n;i++){
    temp+=2*l[i]-2*r[i];
    if(temp>ans)ans=temp;
  }
  printf("%lld\n",ans);
  return 0;
}