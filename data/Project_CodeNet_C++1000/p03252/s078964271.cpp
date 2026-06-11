#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 1e9;

int main(){
  string s,t;
  cin >> s >> t;
  int size = s.length();

  int trace1[26], trace2[26];
  for(int i = 0; i < 26; i++){
    trace1[i] = -1;
    trace2[i] = -1;
  }

  string ans = "Yes";

  for(int i = 0; i < size; i++){
    int sint = s[i]-'a';
    int tint = t[i]-'a';
    if(trace1[sint] < 0) trace1[sint] = tint;
    if(trace2[tint] < 0) trace2[tint] = sint;
    if(trace1[sint] >= 0 && trace1[sint] != tint) ans = "No";
    if(trace2[tint] >= 0 && trace2[tint] != sint) ans = "No";
  }

  cout << ans << endl;



  return 0;
}