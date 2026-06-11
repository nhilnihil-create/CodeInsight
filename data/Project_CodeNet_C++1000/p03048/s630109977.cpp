#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

int main(){
  int R, G, B, N;
  cin >> R >> G >> B >> N;
  //入力終了

  int ans = 0;
  rep(r, N+1){
    rep(g, N/G+1){
      // Rr+Gg+Bb=N より
      // (N-Rr-Gg)/B = b
      //が自然数となればよい
      double tmp = (double)(N - R*r - G*g)/B;

      //割り切れるという条件
      if(tmp == (int)tmp ){
	//さらに，自然数という条件
	if(tmp >= 0)
	  ans++;
      }
    }
  }

  //解答
  cout << ans << endl;
  
  return 0;
}
