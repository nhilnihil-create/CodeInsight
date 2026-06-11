#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  char next;
  set<string> SE;
  for (int i = 0; i < N; i++) {
    string S;
    cin >> S;
    if (SE.count(S)>0){
      cout << "No" << "\n";
      return 0;
    }
    if (i>0 && S.front() != next){
      cout << "No" << "\n";
      return 0;
    }
    
    SE.insert(S);
    next = S.back();
  }
  cout << "Yes" << "\n";
}