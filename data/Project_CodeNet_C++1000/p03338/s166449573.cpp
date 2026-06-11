#include <iostream>
#include <map>
#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

int main(void){
  int N;
  string S;
  cin >> N >> S;
  //入力終了

  int max = 0;
  rep(i, N){
    //前半の文字列の出現状況を記録
    int appeared[26]={0};
    rep(j, i+1)
      appeared[S[j]-'a']++;
    
    //appeared[]を元に共通文字があればcountを更新
    map<char, int> map;
    for(int j=i+1; j<N; j++)
      if(appeared[S[j]-'a' ] > 0)
	map[S[j] ]++;
    //最大値の更新
    if(map.size() > max)
      max = map.size();
  }

  //解答
  cout << max << endl;

  return 0;
}
