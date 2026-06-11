#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cstdio>
using namespace std;
typedef pair<int,int> P;
typedef pair<P,int> P2;
P2 mk_P(int a,int b,int c){
  return P2(P(a,b),c);
}
int pow(int x,int y){
  if(y==0) return 1;
  int ret=pow(x,y/2);
  ret*=ret;
  if(y%2==1) ret*=x;
  return ret;
}
int main(){
  int L;
  cin>>L;
  int p=1,cnt=0;
  while(p<=L){
    p*=2;
    cnt++;
  }
  p/=2;
  cnt--;
  vector<P2> ans;

  for(int i=1;i<=cnt;i++){
    ans.push_back(mk_P(i,i+1,0));
    ans.push_back(mk_P(i,i+1,pow(2,i-1)));
  }
  int L2=L;
  L2-=pow(2,cnt);
  int c=1;
  int L3=pow(2,cnt);
  while(L2>0){
    if(L2%2==1){
      ans.push_back(mk_P(c,cnt+1,L3));
      L3+=pow(2,c-1);
    }
    L2/=2;
    c++;
  }
  cout<<cnt+1<<" "<<ans.size()<<endl;
  for(int i=0;i<ans.size();i++){
    cout<<ans[i].first.first<<" "<<ans[i].first.second<<" "<<ans[i].second<<endl;
  }
}
