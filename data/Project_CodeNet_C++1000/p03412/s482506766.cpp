#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
using namespace std;
typedef long long ll;

int main(){
  int N;
  cin >> N;
  int a[N], b[N];
  for(int i = 0; i < N; i++) cin >> a[i];
  for(int i = 0; i < N; i++) cin >> b[i];

  sort(a, a + N);
  sort(b, b + N);

  int ans = 0;
  //kビットが1になるようなai+bjの個数を求め、ansに足す。
  for(int k = 0; k < 30; k++){
    int aa[N];
    int bb[N];
    for(int i = 0; i < N; i++){
      aa[i] = a[i] % (1 << (k + 1));
      bb[i] = b[i] % (1 << (k + 1));
    }

    sort(aa, aa + N);
    sort(bb, bb + N);

    int T = (1 << k);
    ll cnt = 0;
    //aを固定して2^k <= x < 2^k+1, 2^k+2 <= x < 2^k+3の個数
    for(int i = 0; i < N; i++){
      auto ind1 = lower_bound(bb, bb + N, T - aa[i]);
      auto ind2 = lower_bound(bb, bb + N, 2 * T - aa[i]);
      auto ind3 = lower_bound(bb, bb + N, 3 * T - aa[i]);
      auto ind4 = lower_bound(bb, bb + N, 4 * T - aa[i]);
      cnt += (ind2 - ind1) + (ind4 - ind3);
    }

    if(cnt % 2 == 1){
      ans += (1 << k);
    }
  }

  cout << ans << endl;
  return 0;
}
