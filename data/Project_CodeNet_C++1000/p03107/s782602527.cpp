#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
  string S;
  cin >> S;

  ll cnt0 = 0;
  ll cnt1 = 0;
  rep(i,0,S.size()){
    if(S[i] == '0') cnt0++;
    if(S[i] == '1') cnt1++;
  }
  cout << 2*min(cnt0,cnt1) << endl;
  return 0;
}