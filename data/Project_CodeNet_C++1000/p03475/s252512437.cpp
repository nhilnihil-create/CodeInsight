#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  long long n;
  cin >> n;
  vector<long long> timetonextst(n);
  vector<long long> firsttrain(n);
  vector<long long> cycle(n);
  for(long long i = 0; i < n-1; i++){
    cin >> timetonextst[i] >> firsttrain[i] >> cycle[i];
  }

  for(long long i = 0; i < n; i++){
    if(i == n-1){
      cout << 0 <<endl;
      return 0;
    }
    long long ans = 0;
    ans += firsttrain[i] + timetonextst[i];
    for(long long j = i + 1; j < n -1; j++){
      if(ans <= firsttrain[j]){
        ans = firsttrain[j];
      } else{
        if(ans % cycle[j] != 0){
          ans += cycle[j] - ans % cycle[j];
        }
      }
      ans += timetonextst[j];
    }
    cout << ans <<endl;
  }
}
