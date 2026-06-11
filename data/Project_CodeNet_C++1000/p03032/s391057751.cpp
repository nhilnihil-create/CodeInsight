#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int n, K;
  cin >> n >> K;
  vector < ll > a(n + 1);
  for(int i = 1; i <= n; i++) cin >> a[i];

  int ans = 0;
  for(int k = 1; k <= K; k++){
    for(int i = 0; i <= k; i++){
      vector < int > v;
      for(int j = 1; j <= i && j <= n; j++) v.push_back(a[j]);
      for(int j = n; j >= 1 && j > n - (k - i) && j > i; j--) v.push_back(a[j]);
      int left = K - k, sum = 0;
      sort(v.begin(), v.end());
      for(int j = 0; j < v.size(); j++){
        sum += v[j];
        if(left > 0 && v[j] < 0){
          sum -= v[j];
          left--;
        }
      }
      ans = max(ans, sum);
    }
  }

  cout << ans << '\n';
}
