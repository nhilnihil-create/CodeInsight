#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef int64_t Int;
using namespace std;

map<Int, int> factor;

//---------- 素因数分解 ----------
void prime_factor(Int n) {
  for(Int i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      factor[i]++;
      n /= i;
    }
  }
  if(n != 1) factor[n]++;
}

int main(){
    int N; cin >> N;
    
    for(Int i = 2; i <= N; i++) prime_factor(i);

    int cnt2 = 0, cnt4 = 0, cnt14 = 0, cnt24 = 0, cnt74 = 0;
    for(auto itr = factor.begin(); itr != factor.end(); itr++){
        pair<Int, int> cur = *itr;
        if(cur.second >= 2) cnt2++;
        if(cur.second >= 4) cnt4++;
        if(cur.second >= 14) cnt14++;
        if(cur.second >= 24) cnt24++;
        if(cur.second >= 74) cnt74++;
    }

    //(2,4,4), (2,24), (14,4), (74)
    int ans = 0;
    if(cnt4 > 1) ans += cnt4*(cnt4-1)/2 * (cnt2-2);
    if(cnt24 > 0) ans += cnt24 * (cnt2-1);
    if(cnt14 > 0) ans += cnt14 * (cnt4-1);
    ans += cnt74;
    cout << ans << endl;
}