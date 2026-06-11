#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, c, max=0;
  string s;
  cin >> N;
  vector<string> blue(N);
  
  for(int i=0;i<N;i++){
    cin >> blue.at(i);
  }
  
  cin >> M;
  vector<string> red(M);
  
  for(int i=0;i<M;i++){
    cin >> red.at(i);
  }
  
  for(int i=0;i<N;i++){
    s=blue.at(i);
    c=0;
    for(int j=0;j<N;j++){
      if(blue.at(j) == s)
        c++;
    }
    for(int j=0;j<M;j++){
      if(red.at(j) == s)
        c--;
    }
    if(max < c)
      max = c;
  }
  
  cout << max << endl;
  
}
