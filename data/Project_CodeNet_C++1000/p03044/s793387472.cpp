#include <bits/stdc++.h>
using namespace std;
using  P=pair<long long,long long>;
int main(){
  long long N;
  cin>>N;
  vector<vector<long long>> vec(N);
  map<P,long long> mp;
  vector<long long> color(N);
  for(long long i=0;i<N-1;i++){
    long long a,b,c;
    cin>>a>>b>>c;
    c%=2;
    vec.at(a-1).push_back(b-1);
    vec.at(b-1).push_back(a-1);
    mp[make_pair(a-1,b-1)]=c;
    mp[make_pair(b-1,a-1)]=c;
  }
  color.at(0)=0;
  vector<long long> dist(N,-1);//全頂点を「未訪問」に初期化
  queue<long long> que;
  dist[0]=0;
  que.push(0);
  while(!que.empty()){
    long long v=que.front();//キューから先頭頂点を取り出す
    que.pop();
    //v から辿れる頂点をすべて調べる
    for(long long i=0;i<(long long)vec.at(v).size();i++){
      long long nv=vec.at(v).at(i);
      if(dist[nv]!=-1)continue;//すでに発見済みの頂点は探索しない
      //新たな白色頂点 nv について距離情報を更新してキューに追加する
      dist[nv]=dist[v]+mp[make_pair(v,nv)];
      color.at(nv)=dist[nv]%2;
      que.push(nv);
    }
  }
  for(long long i=0;i<N;i++){
    cout<<color.at(i)<<endl;
  }
}