#include<bits/stdc++.h>
using namespace std;




int N, utmp, vtmp, wtmp;
vector<vector<pair<int,int>>> G;
vector<int> color;
vector<bool> seen;


//dfs
void dfs(int v){

  //cout << "dfs: v=" << v+1 << endl;

  seen[v] = true;

  for(auto next : G.at(v)){
    int vnext = next.first;
    int dist = next.second;
    //頂点nextが滞在済なら無視
    if(seen[vnext] == true) continue;
    else{
      //頂点nextが滞在済みでなければ、まずnextに色をつける
      if((dist % 2) == 0) color[vnext] = color[v]; //vからnexttまでの距離が偶数ならvと同じ色
      else color[vnext] = (-1) * color[v] + 1; //距離が奇数ならvと違う色
    }
    dfs(vnext);
  }

}

int main(){


  //入力を受け取ってグラフを構成
  cin >> N;
  G.resize(N);
  for(int i=0; i<N-1; i++){
    cin >> utmp >> vtmp >> wtmp;
    utmp--;vtmp--;
    //Gに(vtmp,wtmp)要素を追加
    G.at(utmp).push_back(make_pair(vtmp,wtmp));
    G.at(vtmp).push_back(make_pair(utmp,wtmp));
  }

  //for(int i=0;i<N;i++){
  //  cout << "v=" << i << ":" << endl;
  //  for(auto v : G.at(i))
  //    cout << "(vnext,w)=(" << v.first << "," << v.second << ")" << endl;
  //}

  //訪れたかどうかのフラグ、初期設定
  seen.resize(N);
  for(int i=0;i<N;i++) seen[i]= false;

  //色初期設定
  color.resize(N);
  for(int i=0;i<N;i++) color[i]=0;

  //dfsしながら色塗り、最初は頂点0を色1としてからdfs呼び出し
  //グラフは連結と仮定
  color[0]=0;
  dfs(0);

  //output
  for(int i=0; i<N; i++)
    cout << color[i] << endl;
}
