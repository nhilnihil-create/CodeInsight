#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
  string S; cin >> S;

  ll ans = 0;
  ll cnt1=0, cnt2=0;
  rep(i,0,S.size()){
    int n = S[i] - '0';
    if(i % 2 == 0 && n == 1) cnt1++; 
    if(i % 2 == 1 && n == 0) cnt1++;
  }
  rep(i,0,S.size()){
    int n = S[i] - '0';
    if(i % 2 == 0 && n == 0) cnt2++; 
    if(i % 2 == 1 && n == 1) cnt2++;
  }
  ans = min(cnt1,cnt2);
  cout << ans << endl;
  return 0;
}