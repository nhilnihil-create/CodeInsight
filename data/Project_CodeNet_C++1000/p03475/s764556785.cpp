#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int N;
vector<ll> C,S,F;

ll solve(int i, ll time){
  // 駅iにtime秒目にいた時に、駅Nに到着する時刻
  if(i == N-1){
    return time;
  } else { 
    if(time <= S[i]){
      return solve(i+1, S[i] + C[i]);
    } else { 
      // time以降で、F[i]で割り切れるときに移動できる
      ll tmp = time % F[i];
      if(tmp == 0){
        return solve(i+1, time + C[i]);
      } else {
        return solve(i+1, time + (F[i] - tmp) + C[i]);
      }
    }
  }
}

int main(){
  cout << setprecision(10);
  cin >> N;
  C.assign(N,0);
  S.assign(N,0);
  F.assign(N,0);
  for(int i = 0; i < N; i++){
    cin >> C[i] >> S[i] >> F[i];
  }

  vector<ll> ans(N,0);
  for(int i = 0; i < N ; i++){
    cout << solve(i,0) << endl;
  }
  
}
