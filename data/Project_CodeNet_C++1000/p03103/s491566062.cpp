#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VVL vector<vector<ll>>

int main(){
  ll N, M;
  cin >> N >> M;
  VVL a(N, VL(2,0));
  VL c(N);
  rep(i,0,N){
    cin >> a[i][0] >> a[i][1];
  }
  
  //特定キーでのソート　要素0,1...ex)要素1/////////////////////////////////////////// 
  sort(a.begin(), a.end(),
    [](const VL &alpha, const VL &beta)
    {return alpha[0]<beta[0];});
  
  ll num = 0, ans = 0;
  rep(i,0,N){
    num = min(a[i][1], M);
    ans += num * a[i][0];
    M -= num;
    if(M == 0) break;
  }
  cout << ans << endl;
  return 0;
}
