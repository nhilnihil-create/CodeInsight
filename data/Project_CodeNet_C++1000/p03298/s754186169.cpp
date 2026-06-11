#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;
  string S1 = S.substr(0, N);
  map<pair<string, string>, int> mp;
  for (int i = 0; i < (1 << N); i++){
    string red = "";
    string blue = "";
    for (int j = 0; j < N; j++){
      if (i >> j & 1){
        red += S1[j];
      } else {
        blue += S1[j];
      }
    }
    mp[make_pair(red, blue)]++;
  }
  long long ans = 0;
  string S2 = S.substr(N);
  for (int i = 0; i < (1 << N); i++){
    string red = "";
    string blue = "";
    for (int j = N - 1; j >= 0; j--){
      if (i >> j & 1){
        red += S2[j];
      } else {
        blue += S2[j];
      }
    }
    ans += mp[make_pair(blue, red)];
  }
  cout << ans << endl;
}