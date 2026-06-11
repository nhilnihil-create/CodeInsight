#include <bits/stdc++.h>
using namespace std;

template <typename T>
void fin(T a){
  cout<<a<<endl;
  exit(0);
}
/*
最小のQ個を取り出すことは当然出来る
一番小さいのが1つだけ-LINFとかで飛び抜けてるとそれを避けるように動きたい
答えでの最小値Xを固定すると、いや微妙
各Yを固定してそれに対する答えを出す？
*/

signed main(){
  priority_queue<int,vector<int>,greater<int>> que,tmp;
  int N,K,Q,ans=1e9;cin>>N>>K>>Q;
  std::vector<int> v(N);
  for(int i=0;i<N;i++)cin>>v[i];if(Q==1)fin(0);
  for(int i=0;i<N;i++){
    while(que.size())que.pop();
    while(tmp.size())tmp.pop();
    int Y=v[i],let=max(0,i-K+1)-1,out=0,rit;
    for(int j=max(0,i-K+1);j<i;j++)if(v[j]<Y)let=j;
    for(int j=i+1;j<=let+K;j++){
      if(j>=N)out++;
      else if(v[j]<Y)out++;
    }
    if(out)continue;
    let=0;
    while(true){//Yより小さいのが出るまでガーってやる
      int now=let;if(now==i)now++;
      while(now<N&&v[now]>=Y){
        que.push(v[now++]);
        if(now==i)now++;
      }
      rit=now;//[l,r)が区間
      while((int)(que.size())-K>=0){
        tmp.push(que.top());
        que.pop();
      }
      while(que.size())que.pop();
      if(rit==N)break;
      let=rit+1;
    }
    if(tmp.size()+1<Q)continue;
    for(int j=0;j<Q-2;j++)tmp.pop();ans=min(ans,tmp.top()-v[i]);
  }
  fin(ans);
}
