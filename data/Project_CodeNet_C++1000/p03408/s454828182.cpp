#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
//  cout << N <<endl;
  vector<string> s(N);
  for(int i=0; i<N; ++i) {
    cin >> s.at(i);
//    cout << s.at(i) << endl;
  }
  int M;
  cin >> M;
//  cout << M <<endl;
  vector<string> t(M);
  for(int i=0; i<M; ++i) {
    cin >> t.at(i);
//    cout << t.at(i) << endl;
  }
  
  vector<string> s2;
  vector<int>    s3;
  for(int i=0; i<N; ++i) {
    bool flg=0;
    for(int j=0; j<s2.size(); ++j) {
      if (s2.at(j) == s.at(i)) {
        flg=1;
        s3.at(j) += 1;
      }
    }
    if (flg==0) {
      s2.push_back(s.at(i));
      s3.push_back(1);
    }
  }
/*  
  for(int i=0; i< s2.size(); ++i) {
    cout << s2.at(i) << ' ' << s3.at(i) << endl;
  }
  cout << endl;
*/  
  for(int i=0; i<M; ++i) {
    bool flg=0;
    for(int j=0; j<s2.size(); ++j) {
      if (s2.at(j) == t.at(i)) {
        flg=1;
        s3.at(j) -= 1;
      }
    }
  }
/* 
  for(int i=0; i<s2.size(); ++i) {
    cout << s2.at(i) << ' ' << s3.at(i) << endl;
  }
*/  
  int result = 0;
  for(int i=0; i<s3.size(); ++i) {
    if (result < s3.at(i))
      result = s3.at(i);
  }
  
  cout << result <<endl;

  return 0;
}