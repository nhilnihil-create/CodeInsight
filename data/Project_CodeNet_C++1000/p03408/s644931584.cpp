#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> s(N);
  for( int i=0; i<N; i++ ){
    cin >> s.at(i);
  }
  
  int M;
  cin >> M;
  vector<string> t(M);
  for( int i=0; i<M; i++ ){
    cin >> t.at(i);
  }
  
  int X = 0;
  for( int i=0; i<N; i++ ){
    int tmp = 1;
    for( int j=i+1; j<N; j++ ){
      if( s.at(i) == s.at(j) ){
        tmp++;
      }
    }
    for( int j=0; j<M; j++ ){
      if( s.at(i) == t.at(j) ){
        tmp--;
      }
    }
    if( X < tmp ){
      X = tmp;
    }
  }
  
  cout << X << endl;
}
