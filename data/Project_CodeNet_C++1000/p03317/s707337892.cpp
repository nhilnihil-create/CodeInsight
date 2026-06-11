#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>

int main(){
  ll N, K;  cin >> N >> K;
  ll cnt = 0;
  while(N > 0){
    if(cnt == 0) N -= K;
    else N -= K-1;
    cnt++;
  }
  cout << cnt << endl;
  return 0;
}