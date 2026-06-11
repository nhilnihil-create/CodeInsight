#include <bits/stdc++.h>
using namespace std;

int main () {
  int N; cin >> N;
  string s[N];
  for (int i = 0; i < N; i++) {
    cin >> s[i];
  }
  
  int M; cin >> M;
  string t[M];
  for (int j = 0; j < M; j++) {
    cin >> t[j];
  }
  
  int Xmax = 0;
  string word;
  for (int u = 0; u < N; u++) {
    word = s[u];
    int ans = 0;
    
    for (int x = 0; x < N; x++) {
      if (word == s[x]) {
        ans++;
      }
    }
    for (int y = 0; y < M; y++) {
      if (word == t[y]) {
        ans--;
      }
    }
    
    Xmax = max(Xmax, ans);
    
  }
  
  cout << Xmax << endl;
        
}
