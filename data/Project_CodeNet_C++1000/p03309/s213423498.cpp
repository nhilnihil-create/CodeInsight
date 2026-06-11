#include <iostream>
#include <cmath>
#include <algorithm>

#define rep(i, n) for(int i=1; i<=n; i++)

using namespace std;

int main(){
  int N;
  cin >> N;
  int A[N+1];
  rep(i, N)
    cin >> A[i];
  //入力終わり

  //配列にA[i]-iを入れていく
  int sub[N];
  rep(i, N)
    sub[i] = A[i]-i;

  sort(sub+1, sub+N+1 );

  //sub_absの中央値に設定すれば最適
  int b = sub[N/2 + 1];

  //|A[i]-(b+i)|
  long long ans = 0;
  rep(i, N)
    ans += abs(A[i]-(b+i ) );
    
  //解答
  cout << ans << endl;
  
  return 0;
}
