#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<functional>
#include<vector>
#include<math.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  string blue[N];
  for(int i=0;i<N;i++) cin>>blue[i];
  
  int M;
  cin>>M;
  string red[M];
  for(int i=0;i<M;i++) cin>>red[i];
  
  int cnt_b,cnt_r;
  int ans=0;
  int tmp;
  for(string s:blue){
    cnt_b=0;
    cnt_r=0;
    tmp=0;
    for(string t:blue) if(s==t) cnt_b++;
    for(string u:red) if(s==u) cnt_r++;
    tmp=cnt_b-cnt_r;
    if(tmp<=0) continue;
    ans=max(ans,tmp);
  }
  cout<<ans<<endl;
}