#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main(){
  ll N, x, sum=0;
  cin >> N >> x;
  vector<ll> s(N);
  rep(i, N){
    cin >> s[i];
    sum += s[i];
  }
  sort(s.begin(), s.end());
  int ans = 0;
  if(sum == x){
  	cout << N << endl;
  } else {
    rep(i, N){
      if(s[i] <= x && i != N - 1){
        ans++;
        x -= s[i];
      }
    }
    cout << ans << endl;
  }
}