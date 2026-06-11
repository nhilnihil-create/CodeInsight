#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;  
  vector<string> strn(N);
  for (int i=0;i<N;i++){
    string s;
    cin >>s;
    strn.at(i) = s;
  }
  
  int M;
  cin >>M;
  vector<string> strm(M);
  for (int i=0;i<M;i++){
    string t;
    cin >>t;
    strm.at(i) = t;
  }
  
  int ans = 0;
  
  for (int i=0;i<N;i++){
    int score = 0;
    for (int j=0;j<N;j++){
      if (strn.at(i) == strn.at(j)){
        score++;
      }
    }
    for (int j=0;j<M;j++){
      if (strn.at(i) == strm.at(j)){
        score--;
      }
    }
    ans = max(ans, score);
  }
  
  cout << ans << endl;
}


