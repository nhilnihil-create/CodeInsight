#include <iostream>
#include <algorithm>

#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

int main(){
  int N, x;
  cin >> N >> x;
  int a[N];
  rep(i, N)
    cin >> a[i];
  //入力終了

  //a[i]が小さい子供から処理
  sort(a, a+N);

  int ans = 0;
  rep(i, N-1){
    //a[i]よりも多くお菓子を持っていれば，丁度配れば良い
    if(a[i] <= x){
      ans++;
      x -= a[i];
    }
  }

  //ちょうどa[i]個貰わなければならないことに注意する
  if(a[N-1] == x)
    ans++;

  //解答
  cout << ans << endl;
  
  return 0;
}
