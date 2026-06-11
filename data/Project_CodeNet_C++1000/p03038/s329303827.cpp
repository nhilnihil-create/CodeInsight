#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);++i)
using namespace std;
using ll = long long;
using P= pair<ll,ll>;

int main() {
    ll N,M,A,B,C;
    ll ans=0;
    cin>>N>>M;
    vector<ll> Card(N);
    priority_queue<P> que;
    rep(i,N){
      cin>>A;
      que.push(make_pair(A,1));
    }
    rep(i,M){
      cin>>B>>C;
      que.push(make_pair(C,B));
    }  
    rep(i,N){
      P p=que.top();//一番大きい要素を取り出し
      que.pop();//削除
      ans+=p.first;
      if(p.second>1)//入れ替え枠を使った場合、使用回数を減らす。
      {
        p.second--;
        que.push(p);//使用回数がまだ残っているので、queに戻す。
      }
    }
    cout<<ans<<endl;
    return 0;
}