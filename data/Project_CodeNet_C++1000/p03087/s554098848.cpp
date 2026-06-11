#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>

int main(){
  ll N, Q;
  cin >> N >> Q;
  string S; cin >> S;
  
  VL a(N,0);
  ll cnt = 0;
  rep(i,1,N){
    if(S[i-1] == 'A' && S[i] == 'C'){
      cnt++;
    } 
    a[i] = cnt;
  }
  
  ll l,r;
  rep(i,0,Q){
    cin >> l >> r;
    l--; r--;
    cout << a[r] - a[l] << endl;
  }
  return 0;
}