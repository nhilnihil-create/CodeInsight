#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, M;
  cin >> N;
  string s[N];
  for (int i=0; i < N; i++){
    cin >> s[i];
  }  
  cin >> M;
  string t[M];
  for (int i=0; i < M; i++){
    cin >> t[i];
  }
  int max = -M;
  string str;
  for (int i=0; i < N; i++){
    str = s[i];
    int cnt = 0;
    for (int i=0; i < N; i++){
      if (str == s[i]) cnt++;
    }
    for (int i=0; i < M; i++){
      if (str == t[i]) cnt--;
    }
    if (cnt > max) max = cnt; 
  }
  if (max < 0) max = 0;
  cout << max << endl;
}