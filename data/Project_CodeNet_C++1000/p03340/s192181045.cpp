#include <bits/stdc++.h>
using namespace std;
using lint  = long long;

signed main(){
  lint N; cin >> N;
  vector<lint> a(N);
  for(lint i = 0; i < N; i++) cin >> a[i];
  lint ans = 0, sum = 0, right = 0;
  for(lint left = 0; left < N; left++){
    while(sum + a[right] == (sum ^ a[right])&& right < N){
      sum += a[right];
      right++;
    }
    ans += right - left;
    if(right == left) right++;
    else sum -= a[left];
  }
  cout << ans << endl;
}