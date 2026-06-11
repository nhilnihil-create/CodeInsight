#include <bits/stdc++.h>
const int INF=1e9;
const int MOD=1e9+7;
//const int MOD=998244353;
const long long LINF=1e18;
using namespace std;
//#define int long long
//template
typedef pair<int,int> P;
//main
signed main(){
  int K;cin>>K;
  std::vector<P> e[K];
  for(int i=0;i<K;i++){
    e[i].push_back(P((i+1)%K,1));
    e[i].push_back(P(i*10%K,0));
  }
  std::vector<int> d(K,INF);
  d[1]=0;
  deque<int> que;
  que.push_front(1);
  while(que.size()){
    int p=que.front();que.pop_front();
    for(P q:e[p]){
      if(d[q.first]>d[p]+q.second){
        d[q.first]=d[p]+q.second;
        if(q.second)que.push_back(q.first);
        else que.push_front(q.first);
      }
    }
  }
  cout<<d[0]+1<<endl;
}

/*
解説AC
0~K-1のグラフを作るのはなんとなく考えたけど、10倍と+1だけでどんな数も作られることを考えてなかった
グラフを作ることを考察したら辺をどのように取ったらいいのかもっとしっかり考えるべきだった
01BFSは https://betrue12.hateblo.jp/entry/2018/12/08/000020 この記事がとてもわかりやすかった
とっても鮮やかで好きな問題
*/
