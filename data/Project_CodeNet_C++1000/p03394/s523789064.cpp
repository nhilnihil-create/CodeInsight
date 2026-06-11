#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
  int n;
  cin>>n;

  if(n==3){cout<<"2 5 63"<<endl; return 0;}
  if(n==4){cout<<"2 5 20 63"<<endl; return 0;}
  if(n==5){cout<<"2 5 20 63 12600"<<endl; return 0;}

  set<int>ans;
  int cnt=0,now=0;
  for(int i=1; i<=30000; ++i){
    now=i;
    if(i%6==2)ans.insert(i),cnt+=i;
    if(ans.size()==n)break;
    if(i%6==3)ans.insert(i),cnt+=i;
    if(ans.size()==n)break;
    if(i%6==4)ans.insert(i),cnt+=i;
    if(ans.size()==n)break;
    if(i%6==0)ans.insert(i),cnt+=i;
    if(ans.size()==n)break;
  }
  now++;
  if(cnt%6==2){
    ans.erase(8);
    while(1){
      if(now%6==0){
        ans.insert(now);
        break;
      }
      now++;
    }
  }
  else if(cnt%6==3){
    ans.erase(9);
    while(1){
      if(now%6==0){
        ans.insert(now);
        break;
      }
      now++;
    }
  }
  else if(cnt%6==5){
    ans.erase(9);
    while(1){
      if(now%6==4){
        ans.insert(now);
        break;
      }
      now++;
    }
  }
  for(auto&p:ans)cout<<p<<" ";
}