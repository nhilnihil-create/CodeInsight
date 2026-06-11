#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main(){
  int N;
  string S;
  cin >> N;
  cin >> S;
  vector<int> s(N+1, 0);
  s[0] = 0;
  for(int i = 1; i <= N; i++){
    if(S[i-1] == 'W'){
      s[i] += 0 + s[i-1];
    }else{
      s[i] += 1 + s[i-1];
    }
  }
  int ans = 999999;
  int sum;
  for(int i = 1; i <= N; i++){
    sum = 0;
    if(i == 1){
      sum = s[N]  - s[i];
    }else if(i == N){
      sum = N-1 - s[N-1];
    }else{
      sum = s[N] - s[i] + i-1 - s[i-1];
    }
    ans = min(ans, sum);
  }
  cout << ans << endl;
}
