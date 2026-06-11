#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, M;
  cin >> N;
  vector<string> WIN(N);
  for (int i=0;i<N;i++){
  	cin >> WIN.at(i);
  }
  cin >> M;
  vector<string> LOSE(M);
  for (int i=0;i<M;i++){
  	cin >> LOSE.at(i);
  }
  
  string ANS;
  int max = 0;
  for (int i=0;i<N;i++){
    string s = WIN.at(i);
    int p = 0;
    for (int j=0;j<N;j++){
      string t = WIN.at(j);
      if (s == t)
        p++;
    }
    for (int j=0;j<M;j++){
      string u = LOSE.at(j);
      if (s == u)
        p--;
    }
    if (p > max){
      max = p;
    }
  }
  if (max < 0)
    max = 0;
  cout << max << endl;
}