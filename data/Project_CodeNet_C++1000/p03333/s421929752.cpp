#include <bits/stdc++.h>
const int INF=1e9;
const int MOD=1e9+7;
//const int MOD=998244353;
const long long LINF=1e18;
using namespace std;
#define int long long
//template

//main
signed main(){
  int N;cin>>N;
  std::vector<int> l(N),r(N);
  for(int i=0;i<N;i++)cin>>l[i]>>r[i];
  std::vector<int> used(N,0);
  typedef pair<int,int> P;
  std::vector<P> ll(N),rr(N);
  for(int i=0;i<N;i++)ll[i]=P(l[i],i);
  for(int i=0;i<N;i++)rr[i]=P(r[i],i);
  sort(ll.rbegin(),ll.rend());
  sort(rr.begin(),rr.end());
  int ans=0;int now=0;
  int nowl=0,nowr=0;
  for(int i=0;i<N;i++){
    if(i%2){
      while(used[ll[nowl].second])nowl++;
      int a=ll[nowl].second;
      if(now<l[a]){ans+=l[a]-now;now=l[a];}
      if(now>r[a]){ans+=now-r[a];now=r[a];}
      used[ll[nowl].second]++;
    }
    else{
      while(used[rr[nowr].second])nowr++;
      int a=rr[nowr].second;
      if(now<l[a]){ans+=l[a]-now;now=l[a];}
      if(now>r[a]){ans+=now-r[a];now=r[a];}
      used[rr[nowr].second]++;
    }
  }
  ans+=abs(now);
  int fans=ans;
  fill(used.begin(),used.end(),0);
  ans=now=nowl=nowr=0;
  for(int i=0;i<N;i++){
    if(i%2==0){
      while(used[ll[nowl].second])nowl++;
      int a=ll[nowl].second;
      if(now<l[a]){ans+=l[a]-now;now=l[a];}
      if(now>r[a]){ans+=now-r[a];now=r[a];}
      used[ll[nowl].second]++;
    }
    else{
      while(used[rr[nowr].second])nowr++;
      int a=rr[nowr].second;
      if(now<l[a]){ans+=l[a]-now;now=l[a];}
      if(now>r[a]){ans+=now-r[a];now=r[a];}
      used[rr[nowr].second]++;
    }
  }
  ans+=abs(now);
  cout<<max(ans,fans)<<endl;
}
