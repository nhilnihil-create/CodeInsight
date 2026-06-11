#include<bits/stdc++.h>
using ll=long long;
using namespace std;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}

int main(){
  //input
  int point[210];
  rep(i,210)point[i]=0;//なぜかこの作業を行わなかったら後ろのdp[209]などで巨大な数が発生してしまいエラったので入れた。
  int n,m;
  cin>>n;
  vector<string>s(n);
  rep(i,n)cin>>s[i];
  cin>>m;
  vector<string>t(m);
  rep(i,m)cin>>t[i];
  //prepare
  vector<string>stock(0);
  stock.push_back(s[0]);
  int ct=1;

  //蟻本を完全に無視した解答
  //データの数が非常に少ないのでこれで通ると確信
  //入力データで出てきた文字データを（ダブらないように）ストックに入れる
  //次にストックに入れた文字データの添字に対しpointの添字が対応するが、
  //ｓに出てきた文字データがあれば対応するpointの場所を１増加させ、tに出てきたら1減少させる。
  //最後にpointの中から最大のものを選ぶ。ただし、それが0を下回っていたら0を出力する。

  

  
  Rep(i,1,n){
    ct=1;
    rep(j,stock.size()){
      if(stock[j]==s[i])ct=0;
    }
    if(ct==1)stock.push_back(s[i]);
  }
  rep(i,m){
    ct=1;
    rep(j,stock.size()){
      if(stock[j]==t[i])ct=0;}
    if(ct==1)stock.push_back(t[i]);
  }
  sort(stock.begin(),stock.end());

  rep(i,n){
    rep(j,stock.size()){if(stock[j]==s[i]){point[j]++;break;}
    }}
  rep(i,m){
    rep(j,stock.size()){if(stock[j]==t[i]){point[j]--;break;}
    }}
  int maxpoint=0;//0になる可能性があることに注意
  rep(i,201){maxpoint=max(maxpoint,point[i]);}
  cout<<maxpoint<<endl;

  

    
  return 0;
}
