#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i=(a); i<(b); i++)

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  int hidari_w[N];
  int totalw = 0;
  hidari_w[0] = 0;
  FOR(i,0,N-1) {
    if (S[i] == 'W') {
      hidari_w[i+1] = hidari_w[i]+1;
    }
    else hidari_w[i+1] = hidari_w[i];
  }
  FOR(i,0,N) {
    if(S[i] == 'W') totalw++;
  }
  int ans = N;
  //FOR(i,0,N) {
    //cout << hidari_w[i] << " " << endl;
    //cout << totalw << endl;
  //}
  FOR(i,0,N) {
    int hurimuki;
    if(S[i]== 'W') hurimuki = hidari_w[i] + ((N-totalw) - (i-hidari_w[i]));
    else hurimuki = hidari_w[i] + ((N-totalw) - (i-hidari_w[i]) -1);
    ans = min(ans,hurimuki);
  }
  cout << ans << endl;
    
  
  return 0;
}