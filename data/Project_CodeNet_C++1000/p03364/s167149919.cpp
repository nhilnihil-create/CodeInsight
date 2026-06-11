#include <bits/stdc++.h>
using namespace std;
using ll=long long;
/*
全部転写して調べると300^4

123
456
789

456
789
123

123123
456456
789789
123123
456456
789789

abab
caca
abab
caca

2K*2Kの盤面作ってスライドさしてチェック？
いけるかも
あれ、N^4じゃん
breakあるけど最悪パターンでＴＬＥか
ＷＡはなんだ
どうしよう
ああ、1箇所ＮＧだったら+1+1スライドした場合もＮＧか
1箇所ＯＫだったら、+1+1スライドしたら、スライド箇所だけ調査とか
外側ＮＧだった場合考慮外になる
スライドしても一緒なのか
たしかに比較してる数字いっしょや

*/
int main(){
  ll N; cin>>N;
  ll N2=N*2;
  vector<vector<char>> A(N2,vector<char>(N2,'.'));
  for(ll i=0; i<N; i++){
    for(ll j=0; j<N; j++){
      char c; cin>>c;     
      A[i][j]=c;
      A[i][j+N]=c;
      A[i+N][j]=c;
      A[i+N][j+N]=c;      
    }
  }
  //a始点移動
  ll ans=0;
  for(ll a=0; a<N; a++){
    bool end=false;
    for(ll i=0; i<N; i++){
      for(ll j=i+1; j<N; j++){
        if(A[i][j+a]!=A[j][i+a]){
//cout<<"i:"<<i<<" j:"<<j<<" a:"<<a<<" b:"<<b<<endl;
          end=true;
          break;
        }
      }
      if(end) break;
      if(i==N-1) ans+=N-a;
    }
  }
  //b始点移動
  for(ll b=1; b<N; b++){
    bool end=false;
    for(ll i=0; i<N; i++){
      for(ll j=i+1; j<N; j++){
        if(A[i+b][j]!=A[j+b][i]){
//cout<<"i:"<<i<<" j:"<<j<<" a:"<<a<<" b:"<<b<<endl;
          end=true;
          break;
        }
      }
      if(end) break;
      if(i==N-1) ans+=N-b;        
    }
  }
  cout<<ans<<endl;
}