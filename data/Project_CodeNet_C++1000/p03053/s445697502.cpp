#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  int H,W;
  cin>>H>>W;
  vector<char> vec(H*W);//vecは各頂点の白か黒かを保持
  vector<int> answer(H*W+1,H+W);//各黒点からの距離のうち小さいものを保持(随時更新)
  for(ll i=0;i<H*W;i++){
    cin>>vec.at(i);
  }
  using Graph=vector<vector<int>>;
  Graph G(H*W+1);//グラフのサイズはマス目のサイズ+最初の仮想の点分の1
  for (ll i=0;i<H*W;++i){//グラフの作成
    if(vec.at(i)=='#'){//仮想の点からの辺を定義
      G[H*W].push_back(i);
    }
    if(i%W!=W-1){//左右方向の辺の定義
      G[i].push_back(i+1);
      G[i+1].push_back(i);
    }
    if(i<W*(H-1)){//上下方向の辺の定義
      G[i].push_back(i+W);
      G[i+W].push_back(i);
    }
  }
  vector<int> dist(H*W+1,-2);//全頂点を「未訪問」に初期化(-2だったら未訪問と判断)
  queue<int> que;
  dist[H*W]=-1;//仮想の点をスタートにする
  que.push(H*W);
  while(!que.empty()){
    int v=que.front();//キューから先頭頂点を取り出す
    que.pop();
    for(int nv:G[v]){//vから辿れる頂点をすべて調べる
      if(v==H*W || vec.at(nv)=='.'){ 
        if(dist[nv]!=-2){continue;}//すでに発見済みの頂点は探索しない
        dist[nv]=dist[v]+1;//新たな白色頂点nv について距離情報distを更新してキューに追加する
        answer.at(nv)=min(answer.at(nv),dist[nv]);//各黒点からの距離の最小値を必要に応じて更新
        que.push(nv);
      }
    }
  }
  int rock=0;//rockは各白点の(各黒点からの距離の最小値の)最大値を保持(随時更新)
  for(ll i=0;i<H*W;i++){
    if(vec.at(i)=='.'){rock=max(answer.at(i),rock);}
  }
  cout<<rock<<endl;
}