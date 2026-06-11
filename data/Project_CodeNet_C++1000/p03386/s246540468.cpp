#include <bits/stdc++.h>
using namespace std;


int main() {
  int A,B,K;

  cin >> A >> B >> K;
  set<int> S;

  for(int i=0;i<K;++i){
    if(A+i > B) break;
    cout << A+i << endl;
    S.insert(A+i);
  }

  for(int i=K-1;i>=0;--i){
    if(B-i < A) continue;
    if(!S.count(B-i)){
      cout << B-i << endl;
    }
  }
  return 0;
}
