#include <iostream>
#include <list>
#include <map>
#include <algorithm>
#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

int main(){
  int N, M;
  cin >> N;
  int tmp;
  list<int> D;
  rep(i, N){
    cin >> tmp;
    D.push_back(tmp);
  }
  cin >> M;
  list<int> T;
  rep(i, M){
    cin >> tmp;
    T.push_back(tmp);
  }
  //入力終了

  //問題案が足りていない
  if(N < M){
    cout << "NO" << endl;
    return 0;
  }

  //両方ソートしておく
  D.sort();
  T.sort();

  //小さい難易度から順に一致しているか見ていく
  
  while(1){
    //問題セットを処理できた
    if(T.empty() ){
      cout << "YES" << endl;
      return 0;
    }
    //問題セットが処理できていない，かつ，問題案が先になくなった
    if(D.empty() ){
      cout << "NO" << endl;
      return 0;
    }
    
    //難易度が一致していれば両方pop
    if(D.front() == T.front()){
      D.pop_front();
      T.pop_front();
    }
    //難易度が一致していなければ問題案のみpop
    else
      D.pop_front();
  }

  
  return 0;
}
