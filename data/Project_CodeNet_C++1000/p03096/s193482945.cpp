#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll MOD = 1e9 + 7;
ll dp[201010]; ll sum[201010];
int main(){
  ll N;  cin >> N;
  vector<ll> C(N);
  for(ll i = 0; i < N; i++){ cin >> C[i];}
  
  for(ll i = 0; i < 201010; i++){ dp[i] = 0; sum[0] = 0;}
                                  
  //同じものは圧縮する
  vector<ll> vec;
  ll head = 0; ll tail = 0;
  while( head < N){
    while( tail < N && C[head] == C[tail]){ tail++;}
   vec.push_back(C[head]);
   head = tail;}
  
  dp[0] = 1;  sum[vec[0]]++;
  
  for(ll i = 0; i <(ll)vec.size()-1; i++){ ll color = vec[i+1];
    dp[i+1] += dp[i] + sum[color]; dp[i+1] %= MOD;
    sum[color] += dp[i]; sum[color] %= MOD;}
 
  cout << dp[(ll)vec.size()-1] % MOD << endl; return 0;}
 
  