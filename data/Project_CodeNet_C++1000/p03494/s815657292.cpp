#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;



int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i,N){
    cin >> A.at(i);
  }
  //入力処理完了
  int cnt = 0;
  int ans = 100;
  for(int i = 0; i < N;i++){
    cnt = 0;
    while(A.at(i) %2 == 0){//Aの配列が2で割り切れなくなるまで
      A.at(i) = A.at(i) / 2;
      cnt++;
    }
    if(cnt < ans){
      ans = cnt;
    }
  }
  cout << ans << endl;


}



