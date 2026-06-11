#include<bits/stdc++.h>
using namespace std;

int main(){
  long N;
  cin >> N;
  vector<long> A(N);
  for(int i = 1; i <= N; i++){
    long tmp;
    cin >> tmp;
    A.at(i-1) = tmp - i;
  }
 
  // Aの中央値を計算する
  sort(A.begin(), A.end());
  long med = A.at((A.size()-1)/2);
  
  long ans = 0;
  for(auto a : A){
    ans += abs(a - med);
  }
  cout << ans << endl;
  
  // 距離を返す
  // 出力する
}
