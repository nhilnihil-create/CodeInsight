#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, K, X;
ll A[100010];
ll Anbit[70] = { 0 };
int upb;  //Kのbit数  bit上限
ll res = 0;  //計算結果

/*Kの2進数表記時のbit数*/
int upper_bit(ll K){
  if(K == 0) return 0;
  return upper_bit(K/2) + 1;
}

/*binary bit count   第iビットが立っているか*/
void bbc(ll a){
  for(int i = 1; i <= upb; i++){ if( (a >> (i-1)) & 1) Anbit[i] += 1; }
  return ;
}

/*最も値の大きくなるXを計算*/
ll calc_X(void){
  ll x[70] = {0}; ll mul = 1, xx = 0;  mul = (mul << (upb-1));

  for(int i = upb; i >= 1; i--){
    if(Anbit[i] >= (N+1)/2){ mul /= 2; continue; }
    if(mul + xx <= K) xx += mul; 
      mul /= 2;
  }
  return xx;
}


int main(){
  cin >> N >> K;

  upb = upper_bit(K);  //Kのbit数を計算
  for(int i = 0; i < N; i++){ cin >> A[i]; bbc(A[i]); }
  X = calc_X();

  for(int i = 0; i < N; i++) res += (X ^ A[i]);
  cout <<res << endl;
  return 0;
}