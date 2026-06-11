#include <iostream>
#include <set>

using namespace std;

int main(void){
  int A, B, K;
  cin >> A >> B >> K;
  //入力終了

  set<int> s;

  //AからK番目以内に大きい数字を見る
  for(int n=A ; n<A+K; n++){
    if(A<=n && n<=B)
      s.insert(n);
  }

  //BからK番目以内に小さい数字を見る
  for(int n=B-K+1; n<=B; n++){
    if(A<=n && n<=B)
      s.insert(n);
  }

  //解答
  for(auto x : s)
    cout << x << endl;
  
  return 0;
}
