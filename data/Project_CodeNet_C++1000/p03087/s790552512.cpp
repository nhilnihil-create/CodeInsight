#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  string S;
  cin >> S;
  vector<int> l(Q), r(Q), t(N);
  for(int i = 0; i < Q; i++){
    cin >> l.at(i) >> r.at(i);
  }
  
  for(int i = 0; i < N - 1; i++){
    if(S.at(i) == 'A' && S.at(i+1) == 'C') t.at(i + 1) = t.at(i)+1;
    else t.at(i+1) = t.at(i);
  }
  
  for(int i = 0; i < Q; i++) cout << t.at(r.at(i) - 1) - t.at(l.at(i) - 1) << endl;
}