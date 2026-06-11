#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K;
  cin >> N >> K;
  vector<int> v(N+1,0);
  for(int i =0;i < N; i++){
    int n;
    cin >> n;
    v.at(n)++;
  }
  //実際に何種類あるか確認する
  int c = 0;
  for(auto x : v ){
    if( x != 0) c++;
  }
  //K種類以下の場合、書き換え不要
  if(c <= K ){
    cout << 0 << endl;
    return 0;
  }
  //昇順に並び替え
  sort(v.begin(),v.end());
  int ans = 0,del_c = 0;
  for(auto x : v){
    if( x == 0 ) continue;
    if( del_c == (c - K)) break;
    ans += x;
    del_c++;
  }
  cout << ans << endl;
}
  
  