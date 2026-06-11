#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, K;
  cin >> N >> K;
  //操作 A, 操作 B 合計でN
  //の電光掲示板の整数に Kを足したもの
  int i = 1;
  //最初の整数
  while(N > 0){
    if(i*2 < i+K){
		i *= 2;
    }else{
      i += K;
    }
    N--;
  }
  cout << i << endl;
}