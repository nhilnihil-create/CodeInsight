//基準の人きめて、そこから座標管理すればいいかな
//あれっぽい、3回ソートするやつ
//ワーシャル
//ループする木みたいな感じ
//N^2は無理
//map?
//M^2通り全部しらべるのも無理
//与えられたデータを調べてM通りのチェックか
//数字でソート。数字ごとに矛盾がないか調べるか
//新しく出現した数字は0位置に固定
//1 2 100
//1 3 200
//1 4 400
//2 3 100 とかはきうる
//map[1]=0
//map[2]=100
//とか。
//初期値、1e10とかにするか
//それ配列でいいかも
//LsortだけだとRが乱れてるかも。R先にsort
//関係なかった
//1 7
//5 6
//6 7
//7 8
//これでばぐる。UnionFindかな、ツリーみたいな
//やっぱマップかな
//treeで子どもみつける。
//関連する位置情報うめてく。
//
//map(1,7)=100
//map(7,1)=-100
//1 7
//2 5
//2 9
//3 4
//10 4
//5 6
//6 7
//7 9
//8 9

//1-7-6-5-2
//   -9-8
//     -2
//逆いるか
//ループしてても、1度見てたらスルーでいいのかな
//だめだた

#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<ll> pos;
vector<vector<ll>>T;
vector<bool> seen;
map<pair<ll,ll>,ll> mp;
bool dfs(ll i){
  for(auto next_i:T[i]){
    if(seen[next_i]){
      if(mp[make_pair(next_i,i)]!=pos[next_i]-pos[i])
        return false;
    }
//      cout<<i<<" "<<next_i<<" "<<mp[make_pair(i,next_i)]<<" "<<pos[next_i]-pos[i]<<endl;
    else{
      seen[next_i]=true;
      if(pos[next_i]==1e10){
        pos[next_i]=pos[i]+mp[make_pair(next_i,i)];
      }
      else if(mp[make_pair(next_i,i)]!=pos[next_i]-pos[i])
        return false;
      dfs(next_i);
    }
  }
  return true;
}

int main(){
  ll N,M; cin>>N>>M;
  pos.assign(N+1,1e10);
  seen.assign(N+1,false);
  T.assign(N+1,vector<ll>());
  ll m=1e6;
  for(int i=0; i<M; i++){
    ll L,R,D; cin>>L>>R>>D;
    mp[make_pair(R,L)]=D;
    mp[make_pair(L,R)]=-D;
    T[L].emplace_back(R);
    T[R].emplace_back(L);
    m=min(m,L);
  }
  for(int i=1; i<=N; i++){
    if(pos[i]==1e10)
      pos[i]=0;
    seen[i]=true;
    if(!dfs(i)){
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
  return 0;
}
