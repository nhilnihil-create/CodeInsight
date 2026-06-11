#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<set<int>> S(N);
  for (int i = 0; i < N; i++){
    char a;
    cin >> a;
    S[i].insert(a);
  }
  for (int i = 0; i < N; i++){
    char b;
    cin >> b;
    S[i].insert(b);
  }
  for (int i = 0; i < N; i++){
    char c;
    cin >> c;
    S[i].insert(c);
  }
  int sum = 0;
  for (int i = 0; i < N; i++){
    sum += S[i].size() - 1;
  }
  cout << sum;
}